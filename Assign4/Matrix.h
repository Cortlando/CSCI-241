#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

/**
 *
 * Matrix.h
 *
 * Author:    Cortland Ervins
 * z-ID:      Z1813736
 * Date:      3/19/2019
 *
 *Contains the declataion for the Matrix class.
 */

class Matrix
{
	friend ostream& operator<<(ostream& lhs , const Matrix& rhs );

        friend Matrix operator*(int lhs, const Matrix& rhs);

	private:

	int matrixArray[2][2];

	public:

	Matrix();

	Matrix(const int [2][2]);

	int determinant()const ;

	Matrix operator+(const Matrix& rhs) const;

	Matrix operator*(int rhs)const ;

	Matrix operator*(const Matrix& rhs) const;

	bool   operator==(const Matrix& rhs)const;

        bool   operator!=(const Matrix& rhs) const;
};

#endif
