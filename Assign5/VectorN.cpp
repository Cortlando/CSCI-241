#include "VectorN.h"
#include <iostream> 

using std::ostream;



/***************************************************************
Constructor: VectorN()

Use:Default Constructor for VectorN object

Parameters:none

Returns:none
***************************************************************/

VectorN::VectorN()
{
	vCapacity = 0;

	vArray = nullptr;

}


/***************************************************************
Constructor: VectorN

Use:Initializes VectorN object to values stored in the array values

Parameters:
1.Values[]: Values passed from main
2. n:Used to set the vCapacity

Returns:None
***************************************************************/ 


VectorN::VectorN(const double values[], size_t n)
{
	vCapacity = n;

		if (vCapacity == 0)
		{
			vArray = nullptr;
		}

	vArray = new double[vCapacity];

	for(size_t i=0; i < vCapacity; i++) // Loop puts values from values array into vArray of VectorN object
	{
		vArray[i] = values[i];
	}




}


/***************************************************************
Constructor:VectorN

Use: Initizes a new VectorN object to the same capacity and array contents as the existing VectorN object other

Parameters:

1.Other: An exsisting VectorN object


Returns:none
***************************************************************/ 





VectorN::VectorN(const VectorN& other)
{
	vCapacity = other.vCapacity;

	if (vCapacity == 0)
	{
		vArray = nullptr;
	}

        vArray = new double[vCapacity];

        if(vCapacity != 0)
	{

		for(size_t i=0; i < vCapacity; i++) //Loop puts contents of other array into the vArray of the VectorN object.
		{


	        	vArray[i] = other.vArray[i]; 
       	        }

	}
}


/***************************************************************
Destructor:~VectorN()

Use:Destructs a VectorN object

Parameters: None

Returns:None
***************************************************************/ 




VectorN::~VectorN()
{
	clear(); // Calls clear function

}


/***************************************************************
Function:operator=

Use:Overloads the copy assignment operator. Should Assigns one VectorN object to another.

Parameters:
1.other: A VectorN object that gets copied to another VectorN object


Returns:A VectorN object
***************************************************************/ 

VectorN& VectorN::operator=(const VectorN& other)
{
	if (this == &other) //Checks for self-assignment. If it is, it skips to final step, returning *this
	{
		return *this;
	}

	delete[] this->vArray; //deletes vector array for the object pointed to by this

	this->vCapacity = other.vCapacity; //Sets vector capacityfor the object pointed to by this to the vector capacity of other



	if(this->vCapacity == 0) // If vector Capacity is 0, set the vector array point for the object pointed to by this to nullptr
	{
	 this->vArray = nullptr;
	}	



 	if(this->vCapacity > 0) // If vector Capacity not equal to 0, it uses the vArray pointer to allocate an array of double
	{
	vArray = new double[vCapacity];
	}



	for(size_t i = 0; i < vCapacity; i++) //Copies the contents of the vector array of other into the vector array of the object pointed to by this.
	{
	this->vArray[i] = other.vArray[i];
	}


return *this;
}


/***************************************************************
Function:Clear()

Use:Used in destructor to clean the VectorN object

Parameters:none

Returns:none
***************************************************************/ 





void VectorN::clear()
{
  delete[] vArray;

  vArray = nullptr;

  vCapacity = 0;

}



/***************************************************************
Function:size()

Use:returns the size of the vector

Parameters:none

Returns:none
***************************************************************/




size_t VectorN::size() const
{

	return vCapacity;
}


/***************************************************************
Function:operator<<

Use:overloaded output operator so that VectorN can be sent to standard output

Parameters:
1.lhs: the ostream operator
2.rhs: the VectorN object being printed

Returns: the output
***************************************************************/

ostream& operator<<(ostream& lhs ,const VectorN& rhs)
{
	if( rhs.vCapacity == 0) //If the vector is empty it prints an empty brackets
	{
		lhs << "()";
	        return lhs;
	}


	lhs << "(" ;

	for (size_t i = 0; i < rhs.vCapacity ; i++)
	{

	lhs<< rhs.vArray[i] ;
	lhs<< ",";
	}

	lhs << ")";
 
return lhs;
}


/***************************************************************
Function:operator[] (read-only)

Use:Subscript operator overloaded to porvide accessor methods for the class.

Parameters:
1.index:The part of the vArray being accessed

Returns: The accessed part of the vArray
***************************************************************/


double VectorN::operator[](int index) const
{

	return vArray[index];

}



/***************************************************************
Function:operator[] (read-write)

Use:Subscript operator overloaded to porvide accessor methods for the class.

Parameters:
1.index:The part of the vArray being accessed

Returns: The accessed part of the vArray
***************************************************************/


double& VectorN::operator[](int index)
{

	return vArray[index];
}


/***************************************************************
Function:operator+

Use:Adds two vectors

Parameters:
1.rhs:VectorN object

Returns: Result of Addition
***************************************************************/

VectorN VectorN::operator+( const VectorN& rhs) const
{
	VectorN result;


	if(vCapacity < rhs.vCapacity)             //Sets result.vCapacity to which ever of the two vectors has a lower capacity
		result.vCapacity = vCapacity;
	else
		result.vCapacity = rhs.vCapacity;

	result.vArray = new double[result.vCapacity];

	for(size_t i = 0; i < result.vCapacity; ++i)          //Adds the two vectors together and puts the result in result array
	{
		result.vArray[i] = vArray[i] + rhs.vArray[i];
	}

return result;
}


/***************************************************************
Function:operator-

Use:Subtracts two VectorN objects

Parameters:
1.rhs: VectorN object

Returns:Result of the subtraction
***************************************************************/


VectorN VectorN::operator-(const VectorN& rhs) const
{
	VectorN result;

	if(vCapacity < rhs.vCapacity)                  //Sets result.vCapacity to which ever of the two vectors has a lower capacity

		result.vCapacity = vCapacity;
	else
		result.vCapacity = rhs.vCapacity;

	result.vArray = new double[result.vCapacity];

//	for(size_t i = 0; i < result.vCapacity; ++i)
//	{
//		result.vArray[i] = vArray[i] + rhs.vArray[i];
//	}

	for(size_t i = 0; i< result.vCapacity; ++i)
	{
		result.vArray[i] = vArray[i] - rhs.vArray[i];
	}

return result;
}


/***************************************************************
Function:operator*

Use: Multiplies two VectorN objects and adds the result into a double

Parameters:
1.rhs: A VectorN object

Returns: The result of the multiplication
***************************************************************/ 


double VectorN::operator*(const VectorN& rhs) const
{


	double  result = 0;
	size_t n = 0; //Used for the multiplication loop

	if(vCapacity < rhs.vCapacity) //Sets n to the lowest vCapacity
		n = vCapacity ;
	else
		n = rhs.vCapacity ;

	for(size_t i = 0; i < n; i++)    //Multiplies each part of the vArray and adds the result each time to result
	{

	   result += vArray[i] * rhs.vArray[i];
        }

return result;

}

/***************************************************************
Function:operator*

Use: Multiplies double by VectorN

Parameters:
1.lhs: Double used for multiplying
2.rhs: VectorN used for multiplying

Returns: VectorN object as result
***************************************************************/


VectorN operator*(const double lhs, const VectorN& rhs)
{
	VectorN result;

	result = rhs * lhs; //Calls upon operator written below
	return result;


}

/***************************************************************
Function:operator*

Use:Multiplies VectorN by double

Parameters:
1.rhs:Double used for multiplication

Returns:VectorN
***************************************************************/


VectorN VectorN::operator*(const double rhs) const
{
	VectorN result;

	if(vCapacity == 0)             //If vCapacity is 0, sets VectorN to default constructor
	{
		result.vCapacity = 0;
		result.vArray = nullptr;
	}

	else                          //If vCapacity is not 0, sets result the same way its set up everywhere else
	{
	result.vCapacity = vCapacity ;

	result.vArray = new double[result.vCapacity];
	}

	for(size_t i = 0; i < result.vCapacity; i++)
	{
			result.vArray[i] = vArray[i] *  rhs;
	}

  return result;

}

/***************************************************************
Function:operator

Use: Checks if two VectorN objects are equal

Parameters:
1.lhs: VectorN object
2.rhs: VectorN object

Returns: true or false
***************************************************************/ 


bool operator==(const VectorN& lhs , const VectorN& rhs) 
{
	size_t n;

	if(lhs.vCapacity != rhs.vCapacity) //If the vCapacities of the the VectorN objects aren't equal, the Vectors can't be equal
	{
		return false;
	}

//	if (lhs.vCapacity < rhs.vCapacity)
//		n = lhs.vCapacity;
//	else
//		n = rhs.vCapacity

	n = lhs.vCapacity;   //

	for(size_t i = 0; i < n; i++)  //If any of the elements are not equal to each other, it returns false
	{
		if( lhs.vArray[i] != rhs.vArray[i])
			return false;

	}

return true;

}
