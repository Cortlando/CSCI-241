#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <class T>
void quickSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>&, int, int, bool (*compare)(const T&, const T&));





template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{


	quickSort(set, 0 , set.size()-1 , compare);//Calls recursive quickSort function
}

/***************************************************************
Function:quickSort()

Use:Calls the recursive quick sort function

Parameters:
1.set:The vector set being quicksorted
2.*compare: A pointer to a comparison function that can be used to compare two items of the template type

Returns:N/A
***************************************************************/





template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotPoint = 0;

	if(start < end)
	{
	pivotPoint = partition(set, start, end, compare);  //Get the pivot point
	quickSort(set, start, pivotPoint - 1, compare);    //Sort first sublist
	quickSort(set, pivotPoint + 1, end, compare);      //Sort second sublist
	}
}


/***************************************************************
Function:quickSort()

Use:Performs the recursive calls to implement the quick sort algorithm

Parameters:
1.Set:The vector being quicksorted
2.start:Subscript of the first vector element
3.end:Subscript of the last vector element
4.*compare: Pointer to the comparison function

Returns: None
***************************************************************/

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotIndex, mid;
	T pivotValue, temp;

	mid = (start + end) / 2;

	temp = set[start];
	set[start] = set[mid];
	set[mid] = temp;

	pivotIndex = start;
	pivotValue = set[start];


	for (int scan = start +1; scan <= end; scan++)
	{
		if (compare(set[scan], pivotValue))
		{
			++pivotIndex;

			temp = set[pivotIndex];
			set[pivotIndex] = set[scan];
			set[scan] = temp;
		}
	}

	temp = set[start];
	set[start] = set[pivotIndex];
	set[pivotIndex] = temp;




	return pivotIndex;
}


/***************************************************************
Function:partition()

Use:The function selects a pivot element and then partitions the vector around the pivot.

Parameters:
1.set:The vector being partitioned
2.start:subscript of the first vector element
3.end:subscript of the last vector element
4.*compare:Pointer to the comparison function

Returns:The pivot index
***************************************************************/















#endif
