#ifndef SORTS_H
#define SORTS_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

template<class T>
void buildList(vector<T>& set, const char* fileName)
{
	T item; //item being read from file
	ifstream inFile;  //Used to open file

	inFile.open(fileName);

	if(inFile.fail())
	{
		cout<<"Error on file open" << endl;
		return;
	}

	//std::getline(inFile, item);


	while(inFile)
	{
		inFile >> item;

		if(!inFile)
		{
			break;
		}

		set.push_back(item);
	//	std::getline(inFile, item);


	}

	inFile.close();

}

/***************************************************************
Function:buildList()

Use:Reads the items from the input file and puts them into a vector object

Parameters:
1.set: A reference to a vector object that is used to store the items
2.fileName: The name of the file

Returns:N/A
***************************************************************/


template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int count = 0 ;

	for(int i = 0; i < (int) set.size(); i++)
	{ 
		cout << setw(itemWidth) <<  set[i] << ' ';
		//cout << std::string(itemWidth, ' ');
		count++;

		if(count == numPerLine)
		{
			cout << endl;
			count = 0;
		}
	}
}

/***************************************************************
Function:printList()

Use:Print a list of items stored in a vector

Parameters:
1.set:A reference to a constant vector object that contains the items to print
2.itemWidth:An int specifying the width an individual item should occupy when printed
3.numPerLine:Specifices the max number of items that should be printed in a single line of output

Returns:N/A
***************************************************************/




template <class T>
bool lessThan(const T& item1, const T& item2)
{
	if ( item1 < item2)
		return true;
	else
		return false;
}

/***************************************************************
Function:lessThan()

Use:Tests if item one is smaller than item 2

Parameters:
1.item1:Constant reference to T template object
2.item2:Constant reference to T template object

Returns:True if item1 is less than item 2, false otherwsise
***************************************************************/


template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	if ( item1 > item2)
		return true;
	else
		return false;
}



/***************************************************************
Function:greaterThan()

Use:Tests if item one is greater than item 2

Parameters:
1.item1:Constant reference to T template object
2.item2:Constant reference to T template object

Returns:True if item1 is greater than item2, false otherwise
***************************************************************/




#endif
