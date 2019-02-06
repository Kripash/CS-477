//author 		KRIPASH SHRESTHA
//CLASS 		CS 477
//ASSIGNMENT	HOMEWORK 4 
//FILE 			rearrange


#include <iostream>


//this function rearranges the input array of the size to have the negatives on the leftside of the array and the postivies on the right side of the array.
void rearrange(int array[], int size)
{
	int replace_index = 0;
	for(int i = 0; i < size; i++)
	{
		if(array[i] < 0)
		{
			int temp = array[i];
			array[i] = array[replace_index];
			array[replace_index] = temp;
			replace_index++;
		}
	}
}


int main()
{
	int array[] = {4, 3, -2, 0, 2, 9, -1, 10, 0, 5, 23, -4};
	int size = 12;

	std::cout << "Before Arrangement: " << std::endl;
	for(int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";

	}
	std::cout << std::endl;

	rearrange(array, size);

	std::cout << "After Arrangement: " << std::endl;
	for(int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";

	}
	std::cout << std::endl;
	return 0;
}
