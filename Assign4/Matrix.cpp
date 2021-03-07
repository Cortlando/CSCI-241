#include <iostream>
#include "Matrix.h"

using namespace std;

/***************************************************************
Constructor: Matrix

Use: Default constructor for the Matrix constructor

Parameters: None

Returns: None
***************************************************************/


Matrix::Matrix()
{

matrixArray[0][0] = 1;
matrixArray[0][1] = 0;
matrixArray[1][0] = 0;
matrixArray[1][1] = 1;
}

/***************************************************************
Constructor: Matrix

Use: Fills the matrixArray with numbers from what is passed by the method

Parameters: 2d array of integers

Returns: Nothing
***************************************************************/

Matrix::Matrix(const int i [2][2])
{


matrixArray[0][0] = i[0][0];
matrixArray[0][1] = i[0][1];
matrixArray[1][0] = i[1][0];
matrixArray[1][1] = i[1][1];

}

/***************************************************************
Method: determinant

Use: Calculates the determinant of the matrix

Parameters: None

Returns: Int dertermiant of the matrix
***************************************************************/

int Matrix::determinant() const
{
int determinant;
// a * d subtracted by b * c
determinant = matrixArray[0][0] * matrixArray[1][1] - matrixArray[0][1] * matrixArray[1][0];

return determinant;
}

/***************************************************************
Method:operator+

Use:Adds 2 matrixs together

Parameters:
Matrix&
A reference to a constant matrix object

Returns: The result of the addition
***************************************************************/

Matrix Matrix::operator+(const Matrix& rhs ) const
{
Matrix result;
// Adds the row and column of one array to the same row and column of the other array
result.matrixArray[0][0] = this->matrixArray[0][0] + rhs.matrixArray[0][0];
result.matrixArray[0][1] = this->matrixArray[0][1] + rhs.matrixArray[0][1];
result.matrixArray[1][0] = this->matrixArray[1][0] + rhs.matrixArray[1][0];
result.matrixArray[1][1] = this->matrixArray[1][1] + rhs.matrixArray[1][1];

return result;
}

/***************************************************************
Method:operator*

Use: Multiplies the the elements of the matrix by and integer

Parameters:
rhs
Interger that is passed into the method

Returns: The result of the multiplication
***************************************************************/

Matrix Matrix::operator*(int rhs) const
{
Matrix result;
//Multiplies all the elements of the array by integer that was passed in
result.matrixArray[0][0] = this->matrixArray[0][0] * rhs;
result.matrixArray[0][1] = this->matrixArray[0][1] * rhs;
result.matrixArray[1][0] = this->matrixArray[1][0] * rhs;
result.matrixArray[1][1] = this->matrixArray[1][1] * rhs;

return result;
}

/***************************************************************
Method:operator*

Use:Multiplies two matrices together

Parameters:
Matrix&
A reference to a constant matrix object

Returns: The result of multiplying the two matrices together
***************************************************************/

Matrix Matrix::operator*(const Matrix& rhs) const
{
Matrix result;
//Multiplies the matrices together
result.matrixArray[0][0] = this->matrixArray[0][0] * rhs.matrixArray[0][0] + this->matrixArray[0][1] * rhs.matrixArray[1][0];
result.matrixArray[0][1] = this->matrixArray[0][0] * rhs.matrixArray[0][1] + this->matrixArray[0][1] * rhs.matrixArray[1][1];
result.matrixArray[1][0] = this->matrixArray[1][0] * rhs.matrixArray[0][0] + this->matrixArray[1][1] * rhs.matrixArray[1][0];
result.matrixArray[1][1] = this->matrixArray[1][0] * rhs.matrixArray[0][1] + this->matrixArray[1][1] * rhs.matrixArray[1][1];

return result;
}

/***************************************************************
Method:operator==

Use:Checks if all elements of the left operand are equal to the corresponding right operand

Parameters:
Matrix&
A refernece to a constant Matrix object

Returns: A boolean value
***************************************************************/

bool Matrix::operator==(const Matrix& rhs) const
{

for (int i = 0; i < 2; i++)
{

    for(int j= 0; j < 2; j++)
    {

     if( this->matrixArray[i][j]!=rhs.matrixArray[i][j]) //If an element in the left operand is not equal to the corresponding element in the right operand, return false 
     {
      return false;
     }

    }
}

return true;
}

/***************************************************************
Method:operator!=

Use:Checks if an element in the left operand is not equal to an element in the right operand

Parameters:
Matrix&
A reference to a constant Matrix object

Returns:A boolean value
***************************************************************/

bool Matrix::operator!=(const Matrix& rhs) const
{

for (int i = 0; i < 2; i ++)
{

    for(int j = 0; j < 2; j++)
    {

     if(this->matrixArray[i][j] != rhs.matrixArray[i][j]) //If an element in the left operand is not equal to an element in the right operand return false
     {
      return true;
     }

    }
}

return false;
}

/***************************************************************
Function:operator<<

Use:Prints the Matrix object

Parameters:
lhs: A reference to an ostream object
rhs: A reference to a constant Matrix object

Returns: A reference to an ostream object
***************************************************************/

ostream& operator<<(ostream& lhs, const Matrix& rhs)
{

 cout << "[[" << rhs.matrixArray[0][0] << ", " <<rhs.matrixArray[0][1] << "], [" << rhs.matrixArray[1][0] << ", " << rhs.matrixArray[1][1] << "]]" ;

return lhs;
}

/***************************************************************
Function:operator*

Use:Multiplies a matrix by an integer

Parameters:
lhs: An integer representing the left operand
rhs: A reference to a constant matrix object

Returns: The result of multiplying the matrix
***************************************************************/

Matrix operator*(int lhs, const Matrix& rhs)
{
Matrix result;

result.matrixArray[0][0] = rhs.matrixArray[0][0] * lhs ;
result.matrixArray[0][1] = rhs.matrixArray[0][1] * lhs ;
result.matrixArray[1][0] = rhs.matrixArray[1][0] * lhs ;
result.matrixArray[1][1] = rhs.matrixArray[1][1] * lhs ;

return result;
}


