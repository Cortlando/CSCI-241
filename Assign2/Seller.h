#ifndef SELLER_H
#define SELLER_H

/**
 *
 * Seller.h
 *
 * Author:     Cortland Ervins
 * z-ID:       Z1813736
 * Date:       2/21/2019
 *
 * Contains the declaration for the Seller class.
 */


class Seller
{
    //Data members of the Seller Class

    private:

    char name[31];
    double  salestotal;



   public:


   // Method prototypes for the Seller class

   Seller();
   Seller(const char*, double);

   const char* getName() const;
   double getSalesTotal() const;
   void setSalesTotal(double);
   void print() const;
};

#endif
