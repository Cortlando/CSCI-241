#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <class T>
struct Node
{
	T data;
	
	Node<T>* next;

	Node(const T& = T());

};

template <class T>
Node<T>::Node(const T& data)
{
	this->data = data;
	next = nullptr;
}

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template<class T>
class Queue
{
	friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);
	
	public:

	Node<T>* qFront;
	Node<T>* qBack;
	size_t qSize;

	

	Queue();                                     //Default constructor

	~Queue();

	Queue(const Queue<T>&);                      //Copy Constructor

	Queue<T>& operator=(const Queue<T>&);         //overloaded copy operator
	
	void copyList(const Queue<T>&);
	void clear();

	size_t size() const;

	bool empty() const;



	const T& front() const;
	const T& back() const;
	void push(const T&);

	void pop();
};


template<class T>
Queue<T>::Queue()
{
	qFront = qBack = nullptr;
	qSize = 0;

}

/***************************************************************
Constructor:Queue()

Use:Default constructor for queue object

Parameters:N/A

Returns:N/A
***************************************************************/

template<class T>
Queue<T>::~Queue()
{
	clear();
}

/***************************************************************
Function:~Queue()

Use:Destructor for Queue object

Parameters:N/A

Returns:N/A
***************************************************************/

template<class T>
Queue<T>::Queue(const Queue<T>& other)
{
	// Set the new Queue object to empty
	qFront = nullptr;
	qBack = nullptr;
	qSize = 0;

	//Copy the other Queue's linked list
	copyList(other);
}

/***************************************************************
Constructor:Queue()

Use:Copy Constructor for Queue object

Parameters:
1.other: Reference to Queue object. It is the object that is copied

Returns:N/A
***************************************************************/

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		//Make the left Queue object empty
		clear();

		//Copy the other Queue's linked list
		copyList(other);
	}
   
return *this;
}

/***************************************************************
Function:operator=()

Use:Copies a Queue object to another Queue object

Parameters:
1.other:The Queue object that is being copied.

Returns:A reference to the object that was copied into.
***************************************************************/

template<class T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs)
{
	Node<T>* ptr;

	for (ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
		lhs << ptr->data << ' ';

return lhs;
}

/***************************************************************
Function:operator<<()

Use:Prints out the Queue object

Parameters:
1.lhs: Output operator
2.rhs: The object being printed

Returns: Output
***************************************************************/

template<class T>
void Queue<T>::clear()
{
	if(empty())                //If empty it just returns
		return;
				  //Does the same stuff the constructor does
	qFront = nullptr;
	qBack = nullptr;
	qSize = 0;


}

/***************************************************************
Function:clear()

Use:Clears the Queue Object

Parameters:N/A

Returns:N/A
***************************************************************/

template<class T>
size_t Queue<T>::size() const
{
	return qSize;

}

/***************************************************************
Function:size()

Use: Returns the qSize

Parameters:N/A

Returns: Returns the size Queue 
***************************************************************/

template<class T>
bool Queue<T>::empty() const
{
	if(qSize == 0)
		return true;
	else
		return false;
}

/***************************************************************
Function:empty()

Use:Checks if Queue is empty

Parameters:N/A

Returns:true if queue is empty, false if it has anything
***************************************************************/

template<class T>
const T& Queue<T>::back() const
{
	

	if(empty())
		throw std::underflow_error("Stack underflow on call to back()");

	return qBack->data;
	
}

/***************************************************************
Function:back()

Use:Returns data stored in the back node of the queue.

Parameters:N/A

Returns: The data stored in the back of the queue
***************************************************************/

template<class T>
void  Queue<T>::push(const T& val)
{
	Node<T>* newNode = new Node<T>(val);

	if(empty())
		qFront = newNode;
	else
		qBack->next = newNode;

	qBack = newNode;
	++qSize;
}

/***************************************************************
Function:push()

Use:Inserts val into the back of the queue and increments the queue size.

Parameters:
1.val:Reference to a constant T template object

Returns:N/A
***************************************************************/

template<class T>
void Queue<T>::pop()
{
	if(empty())
		throw std::underflow_error("Stack underflow on call to pop()");

	//Remove first node in list
	Node<T>* delNode = qFront;
	qFront = qFront->next;

	//If queue is now empty, make sure poth pointers are nullptr
	if(qFront == nullptr)
		qBack = nullptr;

	delete delNode;
	--qSize;
}

/***************************************************************
Function:pop()

Use:Removes the item at the front of the queue and decrement the queue size.

Parameters:N/A

Returns:N/A
***************************************************************/

template<class T>
void Queue<T>::copyList(const Queue<T>& other)
{
	Node<T>* ptr;
	
	for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
		push(ptr->data);
}

/***************************************************************
Function:copyList()

Use: Copys the list from other

Parameters:
1.other: Reference to Queue<T> template object

Returns:N/A
***************************************************************/

template<class T>
const T& Queue<T>::front() const
{
	if(empty()) 
		throw std::underflow_error("Stack underflow on call to front()");

	return qFront->data;

}

/***************************************************************
Function:front()

Use:Returns the data stored in the front node of the queue.

Parameters:N/A

Returns:The data stored in the front of queue
***************************************************************/

#endif
