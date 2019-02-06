//author 		KRIPASH SHRESTHA
//CLASS 		CS 477
//ASSIGNMENT	HOMEWORK 3 
//FILE 			bubblesort.cpp

#include <iostream>
using namespace std;


//comment this out to remove all of the outputs for the array displays 
#define ENABLE_OUTPUTS

template <typename T>
void modifiedBubbleSort(int size, T array[])
{
	#ifdef ENABLE_OUTPUTS
	cout << endl << "Before Sorting The Array" << endl;
	for (int i  = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << endl;
	#endif

	int comparisons = 0;
	for(int i = 0; i < ((size)/2); i++)
	{
		for(int j = i; j < (size - i - 1); j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
//			cout << "Left To Right Array " << endl;
//			for (int z = 0; z < 6; z++)
//			{
//				cout << array[z] << " ";
//			}
//			cout << endl;
			comparisons++;
		}

		for(int x = (size-1-i); x > i; x--)
 		{
			if(array[x] < array[x-1])
			{
				int temp = array[x];
				array[x] = array[x-1];
				array[x-1] = temp;
			}
//			cout << "Right to left" << endl;
//			for (int z = 0; z < 6; z++)
//			{
//				cout << array[z] << " ";
//			}
//			cout << endl;
			comparisons++;
		}
		//cout << "The Amount of Comparisons is: " << comparisons << endl;
	}
	#ifdef ENABLE_OUTPUTS
	cout << "The Amount of Comparisons is: " << comparisons << endl;
	cout << endl << "After Sorting The Array" << endl;
	for (int i  = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << endl;
	#endif
}


int main()
{

	int array[] = {6,5,2,8,3,1};
	modifiedBubbleSort<int>(6, array);

	char easy[] = "EASYQUESTION";
	modifiedBubbleSort<char>(12, easy);

	return 0;
}
