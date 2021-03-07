#ifndef VECTORN_H
#define VECTORN_H

#include <cstddef>
#include <iostream>


class VectorN
{
	private:

		double* vArray;     // vector array pointer

		size_t  vCapacity;  // vector capacity


	public:
		VectorN();

		VectorN(const double values[] , size_t n );

		VectorN(const VectorN& other );

		~VectorN();

		VectorN& operator=(const VectorN& );

		void clear();

		size_t size() const;

		VectorN operator+(const VectorN& ) const;

		VectorN operator-(const VectorN& ) const;

      	       double  operator*( const VectorN& ) const;

		VectorN operator*(const double ) const ;

	   friend VectorN operator*(const double, const VectorN& ) ;


	friend	std::ostream& operator<<(std::ostream& , const VectorN& ) ;

		friend bool operator==(const VectorN&, const VectorN&) ;

		double operator[](int ) const;

		double& operator[](int ) ;


} ;


#endif
