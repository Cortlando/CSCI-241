/***********************************************************
CSCI 241 - Assignment 2 - Spring 2019

Progammer: Cortland Ervins
Z-ID: z1813736
Section: 1
Date Due: Feburary 21, 2019

Purpose: This program accepts a single number from the
keyboard representing a temperature in Fahrenheit, converts
it to Centigrade, and displays it.
************************************************************/ 

#include "SellerList.h"


/***************************************************************
Function: main

Use: Creates SellerList object using "sellerData" then prints the contents
of the object. Then uses the "processSalesData" method to process the "sales.txt"

Parameters: None 

Returns: 0

Notes: None
***************************************************************/ 

int main()
{

SellerList SellerList1("sellerData");
SellerList1.print();
SellerList1.processSalesData("sales.txt");
SellerList1.print();
}
