#ifndef STACK_H
#define STACK_H

#include <iostream>


template <class T>
class Stack;

template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template <class T>
class Stack
{
	friend std::ostream& operator << <>(std::ostream&, const Stack<T>&);

	private:

	T* stkArray;
	
	size_t stkSize;

	size_t stkCapacity;

	public:

	Stack();
	Stack(const Stack<T>&);
	~Stack();
	Stack<T>& operator=(const Stack<T>&);

	bool empty() const;
	size_t size() const;
	size_t capacity() const;

	void clear();
	
	

	void push(const T&);
	void pop();
	const T& top() const;

	void reserve(size_t);
};

template <class T>
Stack<T>::Stack()
{
	stkCapacity = 0;
	stkSize = 0;
	stkArray = nullptr;
}

/***************************************************************
Constructor:Stack()

Use:Default constructor for a stack object. Sets everything inside object to zero/nullptr

Parameters:None

Returns:None
***************************************************************/

template <class T>
Stack<T>::~Stack()
{
	delete[] stkArray;
}

/***************************************************************
Method:~Stack()

Use: Destructor method for stack object. Deletes stkArray

Parameters:none

Returns:none
***************************************************************/

template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
	stkCapacity = other.stkCapacity; //Sets stack size and capacity equal to passed values
	stkSize = other.stkSize;

	if (stkCapacity == 0)
		stkArray = nullptr;
	else
		stkArray = new T[stkCapacity];

	for (size_t i = 0; i < stkSize; ++i)       //Sets stkArray equal to stkArray in other
		stkArray[i] = other.stkArray[i];
}

/***************************************************************
Constructor:Stack()

Use:Copy Constructor for Stack object, used when using overloaded copy operator

Parameters:
1.other: A reference to a const Stack<T> object

Returns:None
***************************************************************/


template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this == &other)            //Checks for self assignment
	{
		return *this;
	}

	delete[] this->stkArray;       //Deletes "this" stkArray

	this->stkCapacity = other.stkCapacity;   //Sets size and capacity of the "this" stack to "other stack
	this->stkSize = other.stkSize;

	if (stkCapacity == 0)             //If stkCapacity equals 0, stkArray =nullptr. If not stkArray is filled with dynamic T arrays
		this->stkArray = nullptr;
	else
		stkArray = new T[stkCapacity];

	for (size_t i = 0; i < stkCapacity; ++i)       //Copies "other" stkArray into "this" stkArray
		this->stkArray[i] = other.stkArray[i];

return *this; //Returns this object
}

/***************************************************************
Method:operator=()

Use: Copies a stack object into another stack object

Parameters:
1.other:A reference to a const stack object

Returns:A reference to a stack object
***************************************************************/

template <class T>
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs)
{
	for (size_t i = 0; i < rhs.stkSize; ++i) //Outputs the passed stack object
		lhs << rhs.stkArray[i] << ' ';

	return lhs;
}

/***************************************************************
Function:operator<<()

Use:Prints out specified part of the stkArray in Stack object passed to function

Parameters:
1.lhs:The output
2.rhs:The stack object being printed out

Returns:The part of the stkArray being output
***************************************************************/

template <class T>
void Stack<T>::clear() 
{
	stkSize = 0;
}

/***************************************************************
Method:clear()

Use:Clers the Stack by setting size to zero

Parameters:None

Returns:None
***************************************************************/

template <class T>
size_t Stack<T>::size() const
{
	return stkSize;
}

/***************************************************************
Method:size()

Use:Returns size of the stack

Parameters:None

Returns:Size of the stack
***************************************************************/

template <class T>
size_t Stack<T>::capacity() const
{
	return stkCapacity;
}

/***************************************************************
Method:capacity()

Use:Returns the capacity of the stack

Parameters:none

Returns:Capacity of the stack
***************************************************************/

template <class T>
bool Stack<T>::empty() const
{
	if(stkSize ==0)
		return true;
	else
		return false;
}

/***************************************************************
Method:empty()

Use:Check if stack is empty.

Parameters:none

Returns:If stack is empty, returns true. Otherwise return false.
***************************************************************/

template <class T>
const T& Stack<T>::top() const
{
	if(empty())
		throw std::underflow_error("Stack underflow on call to top()");

	return stkArray[stkSize - 1];


}

/***************************************************************
Method:top()

Use:Returns the top element of the stack array

Parameters:none

Returns:Reference to "T" object template
***************************************************************/

template <class T>
void Stack<T>::push(const T& val)
{
	 if (stkSize == stkCapacity)             //If stack size = capacity and capacity = 0, calls reserve method to increase capacity to one.
                                                 // Otherwise it is increase by doubling capacity
	    {
		if(stkCapacity == 0)
			reserve(1);
		else
			reserve(stkCapacity * 2);
	    }

	stkArray[stkSize] = val;                  //Puts value into the last section of stack
        ++stkSize;                                //Increments stkSize
}

/***************************************************************
Method:Push()

Use:If the stack is full, method calls "reserve()" method to increase capacity of stack array. Then it copies the value into the stack array, and then
increments stack size.

Parameters:
1.val:The value to insert into the stack

Returns:None
***************************************************************/

template <class T>
void Stack<T>::pop()
{
	if(empty())
		throw std::underflow_error("Stack underflow on call to pop()");

	--stkSize;
}

/***************************************************************
Method:pop()

Use:Decrements the stack size

Parameters:None

Returns:None
***************************************************************/

template <class T>
void Stack<T>::reserve(size_t n)
{
	if (n < stkSize || n == stkCapacity) //If n is less than stksize and n=stkCapacity it just returns.
		return;

	T* tempArray = new T[n];            //Declares a tempArray pointer

	for (size_t i = 0; i < stkSize; ++i)  //Fills temparray with stkArray from object
		{
		tempArray[i] = stkArray[i];
		}
	
	stkCapacity = n;                    //Stack Capacity filled with new capacity
	delete[] stkArray;                  //Deletes stkArray
	stkArray = tempArray;               //Sets stkArray = tempArray

}

/***************************************************************
Method:reserve()

Use:Increses the capacity of the stack array

Parameters:
1.n:The new capacity

Returns:None
***************************************************************/

#endif
