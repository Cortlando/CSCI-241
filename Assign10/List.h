#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

template <class T>
struct Node
{
	T data;

	Node<T>* next;

	Node<T>* prev;

	Node(const T& = T());
};

template <class T>
Node<T>::Node(const T& data)
{
	this->data = data;
	next= nullptr;
	prev = nullptr;
}

template <class T>
class List;

template <class T>
std::ostream& operator<<(std::ostream&, const List<T>&);

template <class T>
class List
{
	friend std::ostream& operator<< <>(std::ostream&, const List<T>&);

	public:

	Node<T>* qFront;
	Node<T>* qBack;
	size_t qSize;

	List();                                           //Default Constructor

	~List();                                          //Deconstructor

	List(const List<T>& other);                        //Copy Constructor

	List<T>& operator=(const List<T>& other);

	void copyList(const List<T>&);

	void clear();

	size_t size() const;

	bool empty() const;

	const T& front() const;

	T& front();

	const T& back() const;

	T& back();

	void push_front(const T&);

	void push_back(const T&);

	void pop_front();

	void pop_back();

	bool operator==(const List<T>&) const;

	bool operator<(const List<T>&) const;

};	

template <class T>
List<T>::List()
{
	qFront = qBack = nullptr;
	qSize = 0;

}

template <class T>
List<T>::~List()
{
	clear();
}

template <class T>
List<T>::List(const List<T>& other)
{

	qFront = qBack = nullptr;
	qSize = 0;


	Node<T>* ptr;

	for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
		push_back(ptr->data);
	




	//T& temp = new Node<T>(other);

//	T temp = other;

//	push_back(&other);

	//T* n;
	
	/*
	for( n = other.qFront; n; n = n->next)
	{
        push_back(*n);
	}
	*/

	

}

template <class T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if(this != &other)
	{
		clear();
		 
	
	
	new(this) List(other);

	}

return *this;
	


}

template <class T>
void List<T>::copyList(const List<T>& other)
{


	/*
	Node<T>* ptr;

	for(ptr = other.qFront; ptr != nullptr; ptr->next)
	{
		push(ptr->data);
	}
	*/

}

template <class T>
void List<T>::clear()
{

	qFront = qBack = nullptr;
	qSize = 0;
}

template <class T>
size_t List<T>::size() const
{
	return qSize;
}

template <class T>
bool List<T>::empty() const
{
	if(qSize == 0)
		return true;
	else
		return false;
}

template <class T>
const T& List<T>::front() const
{
	return qFront->data;
}

template <class T>
T& List<T>::front()
{
	return qFront->data;
}

template <class T>
const T& List<T>::back() const
{
	return qBack->data;
}

template <class T>
T& List<T>::back()
{
	return qBack->data;
}

template <class T>
void List<T>::push_front(const T& val)
{
	Node<T>* newNode = new Node<T>(val);
	
	newNode->next = qFront;

	if(empty()==1)
		qBack = newNode;
	else
		qFront->prev = newNode;

	qFront = newNode;
	++qSize;
	
}

template <class T>
void List<T>::push_back(const T& val)
{
	Node<T>* newNode =  new Node<T>(val);

	newNode->prev = qBack;
	
	if(empty()==1)
		qFront = newNode;  
	else
		qBack->next = newNode;

	qBack = newNode;
	++qSize;
//	std::cout << val;
}

template <class T>
void List<T>::pop_back()
{
	if(qSize > 1)
	{
		Node<T>* delNode = qBack;
		qBack = delNode->prev;
		qBack->next = nullptr;
		delete delNode;
	}

	if(qSize == 1)
	{
		Node<T>* delNode = qBack;
		qBack = delNode->prev;
		qFront = nullptr;
		delete delNode;
	}

	--qSize;
}

template <class T>
void List<T>::pop_front()
{
	if(qSize > 1)
	{
		Node<T>* delNode = qFront;
		qFront = delNode->next;
		qFront->prev = nullptr;
		delete delNode;
	}

	if(qSize == 1)
	{
		Node<T>* delNode = qFront;
		qFront = delNode->next;
		qBack = nullptr;
		delete delNode;
	}

	--qSize;

}

template <class T>
bool List<T>::operator==(const List<T>& rhs) const
{

	if(rhs.qSize != this->qSize) //Checks if they are the same size
		return false;

	Node<T>* ptr;

	Node<T>* ptr2;


	for(ptr = rhs.qFront, ptr2 = this->qFront; ptr != nullptr; ptr = ptr->next, ptr2 = ptr2->next)                                 //For loop that compares two node objects that have 
	{										       //data from the two things im comparing	
		

			if(ptr->data  != ptr2->data  )
				return false;
		

	  }
	


return true;
}

template <class T>
bool List<T>::operator<(const List<T>& rhs) const
{

	Node<T>* ptr;

	Node<T>* ptr2;



	for(ptr = this->qFront, ptr2 = rhs.qFront; ptr != nullptr && ptr2 != nullptr; ptr = ptr->next, ptr2 = ptr2->next)
	{	
		if(ptr->data < ptr2->data)
			return true;

		if(ptr->data > ptr2->data)
			return false;

		if(ptr->data == ptr2->data)
			;

		if(ptr == nullptr && ptr!= nullptr)
			return true;

		if((ptr == nullptr && ptr2 == nullptr) || (ptr != nullptr && ptr2 == nullptr))
			return false;


		
	}

}


template <class T>
std::ostream& operator<<(std::ostream& lhs, const List<T>& rhs)
{
	Node<T>* ptr;

	

	for(ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
		lhs << ptr->data << ' ';

return lhs;
}

	












#endif
