#include "Seller.h"

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

/***************************************************************
Constructor: Seller

Use: Default constructor for Seller object

Parameters: none

Returns: none
***************************************************************/

Seller::Seller()
{
 strcpy( name , "");

 salestotal = 0;
}

/***************************************************************
Constructor: Seller

Use: Alternate Constructor for Seller object

Parameters:
const char* newName: A const cstring that won't be changed by the method
double newSalesTotal: Double variable that contains a new sales total

Returns: none
***************************************************************/

Seller::Seller(const char* newName, double newSalesTotal)
{

	strcpy( name, newName);

	salestotal = newSalesTotal;
}


/***************************************************************
Function: getName() const

Use: Returns the name data member

Parameters: none

Returns: name
***************************************************************/


const char* Seller::getName() const
{

return name;

}

/***************************************************************
Function:getSalesTotal() const

Use:Returns the sales total data member

Parameters: none

Returns: salestotal
***************************************************************/

double Seller::getSalesTotal() const
{
return salestotal;
}

/***************************************************************
Function:setSalesTotal

Use: Assigns the newSalesTotal to to the salestotal data member

Parameters:
double newSalesTotal: a dobule variable that contains a new sales total

Returns:none
***************************************************************/

void Seller::setSalesTotal (double newSalesTotal)
{
salestotal = newSalesTotal;
}

/***************************************************************
Function:print() const

Use: Prints the name and salestotal data members

Parameters:none

Returns:none
***************************************************************/

void Seller::print() const
{

    printf("%-30s %9.2f\n",name,salestotal);

}

