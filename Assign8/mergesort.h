#ifndef MERGESORT_H
#define MERGESORT_H

#include <fstream>
#include <string>
#include <iostream>


template <class T>
void mergeSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
void merge(vector<T>&, int, int, int, bool (*compare)(const T&, const T&));


template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	mergeSort(set, 0, set.size() - 1, compare);
}

/***************************************************************
Function:mergeSort()

Use:Calls the recursive mergeSort function to sort the set

Parameters:
1.set: A reference to a vector object containing the list of items to sort
2.*compare: A pointer to a comparison function that can be used to compare two items of the template type

Returns:N/A
***************************************************************/



template <class T>
void mergeSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		

		//Sorts the two sides of the set


		mergeSort(set, start, mid, compare);
		mergeSort(set, mid+1, end, compare);
		
		//Merges them
		merge(set, start, mid, end, compare);
	}
}

/***************************************************************
Function:mergesort()

Use:Divdes a vector into two subvectors, sorts them, and then merges the two sorted subvectors.

Parameters:
1.set: The vector being sorted.
2.start:The subscript of the first vector element
3.end:The subscript of the last vector element
4.*compare: The pointer to the comparison function

Returns:N/A
***************************************************************/

template <class T>
void merge(vector<T>& set, int start, int mid, int end, bool (*compare)(const T&, const T&))
{
	vector<T> temp(end - start + 1);

	int i = start;      // Subscript for start of left sorted subvector
	int j = mid +1;     // Subscript for start of right sorted subvector
	int k = 0;          // Subscript for start of merged vector

	// While not at the end of either subvector
	while (i <= mid && j <= end)
	{
		if (compare(set[i], set[j]))
		{
			temp[k] = set[i]; //Copy element i of set into element k of temp
			++i;
			++k;
		}
		else
		{
			temp[k] = set[j]; //Copy element j of set into element k of temp 
			++j;
			++k;
		}

	}

	//Copy over any remaining elements of left subvector
	while (i <= mid)
	{
		temp[k] = set[i];
		++i;
		++k;
	}

	//Copy over any remaining elements of right subvector
	while (j <= end)
	{
		temp[k] = set[j];
		++j;
		++k;
	}

	//Copy merged elements back into original vector
	for(i= 0, j = start; j <= end; i++, j++)
		set[j] = temp[i];




}

/***************************************************************
Function:merge()

Use:Merges two sorted subvectors

Parameters:
1.set:The result of the merged vectors
2.start:Subscript for start of left sorted subvector
3.mid:Subscript for start of right sorted subvector
4.end:Subscript for start of merged vector
5.*compare:The pointer ot the comparison function

Returns:N/A
***************************************************************/






#endif
