//author 		KRIPASH SHRESTHA
//CLASS 		CS 477
//ASSIGNMENT	HOMEWORK 5
//FILE 			HEAP


//This program DOES CHECK FOR MAX HEAP.

#include <iostream>


bool isMaxHeap(int array[], int size);


//This function prints out the elements of the array and checks if it is a maxHeap or not by calling isMaxHeap and then properly outputs the response to if it is a max heap or not.
void printOut(int array[], int size)
{
	std::cout << "[ ";
	for(int i = 0; i < size; i++)
	{

		std::cout << array[i] << " ";
	}
	std::cout << "] = ";	

	//calls isMaxHeap to check if it is a maxHeap and then properly does the output based on the return.
	if(isMaxHeap(array, size))
	{
		std::cout << "YES,heap" << std::endl;
	}
	else if(!isMaxHeap(array, size))
	{
		std::cout << "Not a heap" << std::endl;
	}
}

/*This function checks to see if the given array of size is a max heap or not. I took the iterative approach and iterated with the (size - 2)/2 of the array. 
  The Loop continues until the stopping condition is met. During this loop, the function checks to see if the current inddex's left and right child is larger than itself. 
  If either children is larger than the parent, the function will return false. Otherwise the function will complete the loop and if it did not return false, it will return true, implying it is a max heap.
*/
bool isMaxHeap(int array[], int size)
{
	for(int i = 0; i <= ((size-2)/2); i++)
	{
		if(array[(2 * i) + 1] > array[i])	//checks if left child is larger than parent.
		{
			return false;
		}
		
		if(array[(2 * i) + 2] > array[i])	//checks if right child is larger than parent.
		{
			return false;
		}
	}
	return true;
}


int main()
{

	int maxHeap[10] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
	int notMaxHeap[9] = {10, 3, 9, 7, 2, 11, 5, 1, 6};

	printOut(maxHeap, 10);
	printOut(notMaxHeap, 9);

	return 0;
}
