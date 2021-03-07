#include "SellerList.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using std::ifstream;
using std::cout;
using std::endl;
using std::left;
using std::setw;

/***************************************************************
Constructor: SellerList()

Use:Default constructor of the SellerList class. Sets numsellers to 0.

Parameters: none

Returns: none
***************************************************************/

SellerList::SellerList()
{
    numsellers  = 0;
}

/***************************************************************
Function: SellerList(const std::string& fileName)

Use:Alternate constructor for the SellerList class. Reads in input file that contains 
seller data.

Parameters:
string& fileName: A c++ string that won't be changed by the method that contains 
the name of an input file of seller data.

Returns:none
***************************************************************/

SellerList::SellerList(const std::string& fileName)
{

    numsellers = 0;

    ifstream inFile;

    inFile.open(fileName);


    if (!inFile)
      {
      std:: cout << "Error - unable to open input file " << fileName << std:: endl;
      exit(1);
      }



      while (inFile) //While in the file, reads the database file into the SellerList Object
      {
      inFile.read((char*) this, sizeof(SellerList));
      }


      for (int  j = 0; j < 30; j++ ) //For loop that counts the number of sellers
      {
          if (strcmp(Sellerlist[j].getName(),"") != 0) // If the part of the array being checked is not empty, increments numsellers
       	 	numsellers++;
          else
             break;
      }

       inFile.close();

 sortSellers(); // Sorts the sellers
}

/***************************************************************
Function:print() const

Use: Prints the name and sales total data members

Parameters:none

Returns:none
***************************************************************/

void SellerList::print() const
{

std::cout << endl <<  "Seller Listing"  << std::endl;

printf("%-30s %9s\n","Name","Sales Total");


for (int k = 0 ; k <  numsellers; k++)
  {
    Sellerlist[k].print(); // Uses print method from Seller to print.
  }

}

/***************************************************************
Function:sortSellers()

Use: Sorts the array of Seller Objects in ascending order by name

Parameters: none

Returns: none
***************************************************************/

void SellerList::sortSellers()
{
int i, j;
Seller bucket;

for (i = 1; i < numsellers; i++)
   {
     bucket = Sellerlist[i];

	for (j = i; (j > 0) && (strcmp(Sellerlist[j-1].getName(), bucket.getName()) > 0); j--) //Compares part of the SellerList array with part
                                                                                              // to the left of it using the Seller bucket object
          {
              Sellerlist[j] = Sellerlist[j-1];


           }
      Sellerlist[j] = bucket;
   }

}


/***************************************************************
Function:searchForSeller()

Use: Searches for a seller.

Parameters:
const char* searchName: a constant C string that contains a name to search for

Returns: If search is successful, returns the index of the array that contains
the number that was searched for. Returns -1 if search fails.

Notes:none
***************************************************************/

int SellerList::searchForSeller(const char* searchName) const
{
 int low = 0;
 int high = numsellers -1;
 int mid;

  while (low <= high)
    {

    mid = (low + high) / 2 ;

    if (strcmp(searchName, Sellerlist[mid].getName()) == 0)
     {
       return mid;
      }

   if (strcmp(searchName, Sellerlist[mid].getName()) < 0)
	{
        high = mid -1;
        }

    else
       {
       low = mid +1;
	}
    }

return -1;
}

/***************************************************************
Function:processSalesData()

Use: Processes sales data into a neat and easy to read format

Parameters:none
string& fileName: a constant C string that contains the name of a file of 
sales data.

Returns:none

Notes:none
***************************************************************/

void SellerList::processSalesData(const std::string& fileName)
{
ifstream inFile;
char lastName[21];
char firstName[11];
double salesAmount;
char name[31];

     inFile.open(fileName);

     if(!inFile)
     {
     std::cerr << "Error - unable to open input file ";
     exit(1);
     }

	inFile >> lastName;
	cout << endl <<  "Sales Transactions\n\n";

	while(inFile)
	{
	 inFile >> firstName;
	 inFile >> salesAmount;
	 			//Next three lines puts the first and last name
                                //Together in the name cstring
	 strcpy(name,lastName);
	 strcat(name, ", ");
	 strcat(name, firstName);

	 int index = searchForSeller(name);

	 if (index == -1)
	   {
	    std::cout << "Error - " << name <<  " does not exist" << endl ;
           }

	 else
	    {

	   cout << name <<  " " << "sold " << salesAmount << endl;

	    Sellerlist[index].setSalesTotal( salesAmount + Sellerlist[index].getSalesTotal()); //Gets sales total from index specified and adds that to the 
                                                                                               //salesAmount. Done inside the setSalesTotal method.

	    }

         inFile >> lastName;
         }

inFile.close();
}


