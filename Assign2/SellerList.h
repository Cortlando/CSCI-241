#ifndef SELLERLIST_H
#define SELLERLIST_H

#include "Seller.h"
#include <string>
#include <iostream>
#include <iomanip>

using std::ifstream;

class SellerList
{

         // Data members for the SellerList class

         private:

         Seller Sellerlist[31];
         int numsellers;

         // Initalizes the methods for the SellerList class
         public:

         SellerList();
         SellerList(const std::string& fileName);
         void  print() const;
         void sortSellers();
         int searchForSeller(const char* searchName) const;
         void processSalesData(const std::string& fileName);
};

#endif
