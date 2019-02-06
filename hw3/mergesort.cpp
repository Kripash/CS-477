//author 		KRIPASH SHRESTHA
//CLASS 		CS 477
//ASSIGNMENT	HOMEWORK 3 
//FILE			mergesort.cpp

#include <iostream>
#include <cmath>
using namespace std;


//comment this out to remove all of the outputs for the array displays 
#define ENABLE_OUTPUTS

template <typename T>
void modifiedSort(T array[], T temp[], int left, int middle, int right, int size);

template <typename T>
void modifiedMergeSort(int size, T array[])
{
	#ifdef ENABLE_OUTPUTS
	cout << endl << "Before Sorting The Array" << endl;
	for (int i  = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << endl;
	#endif

	T temp[size] = {0};
	int mergestep = 0;
	for(int i = 1; i < size; i *= 2)
	{
		#ifdef ENABLE_OUTPUTS
		cout << pow(2,mergestep) << "-by-" << pow(2,mergestep) << " merge" << endl;
		#endif
		for(int j = 0; j < size; j = j + 2 * i)
		{
			int left_partition, mid, right_partition;
			left_partition = j;
			mid = j + i;
			right_partition = j + (2 * i);
			if(left_partition >= size)
			{
				left_partition = size;
			}
			if(mid >= size)
			{
				mid = size;
			}
			if(right_partition >= size)
			{
				right_partition = size;
			}			
			//cout << left_partition << " " << mid << " " << right_partition << endl;
			modifiedSort(array, temp, left_partition, mid, right_partition, size);
			#ifdef ENABLE_OUTPUTS
	
			for(int inc = left_partition; inc < right_partition; inc++)
			{
				cout << temp[inc] << " ";
			}
			cout << endl;
			#endif
		}
		for(int z = 0; z < size; z++)
		{
			array[z] = temp[z];
		}
		#ifdef ENABLE_OUTPUTS
		cout << "MERGE STEP " << mergestep  << " ARRAY" << endl;
		mergestep++;
		for (int i  = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl << endl;
		#endif
	}

	#ifdef ENABLE_OUTPUTS
	cout << "After Sorting The Arraay" << endl;
	for (int i  = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << endl;
	#endif
}

template <typename T>
void modifiedSort(T array[], T temp[], int left, int middle, int right, int size)
{
	int i = left;
	int j = middle;
	int k = left;

	while(i < middle || j < right)
	{
		if( i < middle && j < right)
		{
			if(array[i] < array[j])
			{
				temp[k] = array[i];
				k++;
				i++;
			}
			else
			{
				temp[k] = array[j];
				k++;
				j++;
			}
		}
		else if(i == middle)
		{
			temp[k] = array[j];
			k++;
			j++;
		}
		else if(j == right)
		{
			temp[k] = array[i];
			k++;
			i++;
		}
	
		/*for (int i  = 0; i < size; i++)
		{
			cout << temp[i] << " ";
		}
		cout << endl;*/
	}
}

int main()
{
	
	int array[] = {3,2,5,1};
	modifiedMergeSort<int>(4, array);

	char example[] = "ASORTINGEXAMPLE";
	modifiedMergeSort<char>(15, example);	

	return 0;
}
