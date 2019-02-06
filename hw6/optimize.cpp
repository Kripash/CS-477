//Author: Kripash Shrestha
//File: optimize.cpp
//Homework 6 CS 477

#include <iostream> 
#include <iomanip>
#include <algorithm>

using namespace std;


#define POSSIBLE_SITES 4	//macro for the possible x values
#define MILES 20			//macro for the total miles on the highway
#define MAX_SEPARATION 5	//macro for the min separation distance per billboard


//struct used for optimization problem
struct billboard_optimize
{
	int revenue;	//revenue up to this subproblem
	int index;		//most recent index for the subproblem

};



/*
The following code uses a bottom up approach to solving the highway advertisement optimization revenue problem. 
The results of the subproblems are stored in a 2D array of billboard_optimize struct. 
The problem uses a similar approach to the one used for Knapsack 0-1 problem. 
The algorithm first sets all of the non used spots to the previous element's values. 
The algorithm them checks to see if the advertisement spot can be used, and if it can, the algorithm places it if there is no issues. 
If there is an issue, the algorithm will see which adverisements need to be removed and remove those appropriately and update the index.
*/
int optimizeRevenue(int r_index, int x_array[], int r_array[], billboard_optimize rev_array[][MILES + 1], int used_billboards[])
{
	for(int i = 0; i <= POSSIBLE_SITES; i++, r_index++)
	{
		for(int j = 0; j <= MILES; j++)
		{
			if(i > 0 )
			{
				rev_array[i][j].revenue = rev_array[i-1][j].revenue;
				rev_array[i][j].index = rev_array[i-1][j].index;
			}
			if(i == 0 || j == 0)
			{
				rev_array[i][j].revenue = 0;
				rev_array[i][j].index = 0;		
			}
			else if((x_array[r_index - 1] != j))
			{
				rev_array[r_index][j].revenue = max(rev_array[r_index][j-1].revenue, rev_array[r_index][j].revenue);
				rev_array[r_index][j].index = max(rev_array[r_index][j-1].index, rev_array[r_index][j].index);
			}
			else
			{
				if(j <= MAX_SEPARATION)
				{
					rev_array[r_index][j].revenue = max(rev_array[r_index][j - 1].revenue, r_array[r_index - 1]);
					if(r_array[r_index - 1] > rev_array[r_index][j - 1].revenue)
					{
						rev_array[r_index][j].index = r_index;
					}
				}
				else
				{
					rev_array[r_index][j].revenue = max((rev_array[r_index][j - MAX_SEPARATION - 1].revenue + r_array[r_index - 1]), rev_array[r_index][j - 1].revenue);
					if(rev_array[r_index][j - 1].revenue > (rev_array[r_index][j - MAX_SEPARATION - 1].revenue + r_array[r_index - 1]))
					{
					}
					else if (rev_array[r_index][j - 1].revenue <= (rev_array[r_index][j - MAX_SEPARATION - 1].revenue + r_array[r_index - 1]))
					{
						rev_array[r_index][j].index = r_index;
					}
				}
			}
		}
	}

	
	int max_index = rev_array[POSSIBLE_SITES][MILES].index; 
	used_billboards[max_index - 1] = 1;
	int i = max_index - 1;
	for(int j = max_index - 2; j >= 0; j--)
	{
		if(i > 0)
		{
			if(x_array[i] - x_array[j] > MAX_SEPARATION)
			{
				used_billboards[j] = 1;
				i = j;
				j--;
			}
		}
	
	}

	return rev_array[POSSIBLE_SITES][MILES].revenue;
} 


/*
The function prints the auxiliary table for the locations.
This algorithm uses a bottom up approach of the auxillary table to print the contents within the auxuliary table. 
The problem goes through the auxiliary table and marks displays the advertisements used, 1 for used and 0 for not used.
*/
void printAuxiliaryTable(int used_billboards[])
{
	cout << "Auxiliary Table containing the billboards/advertisement used (0 indicates not used, 1 indicates used)" << endl;
	for(int i = 0; i < POSSIBLE_SITES; i++)
	{	
		cout << setw(1) << "x" << i << " ";
	}
	cout << endl;

	for(int i = 0; i < POSSIBLE_SITES; i++)
	{	
		cout << setw(2) << used_billboards[i] << " ";
	}
	cout << endl;

}

/*
The function function prints the location used with the revenues and the advertisement used in each location. 
If the index is 0:
The function prints out the revenue on each location used on the highway.
The function then prints out the appropriate indexed advertisement used on the highway.
If not: 
The function goes and appropriately marks the arrays used for displays based on the x_array, r_array values and the locations used and billboards to make the proper display.

*/
void printLocationsUsed(int used_billboards[], int curr_index, int locations_used[], int x_array[], int r_array[], int advertisement_in_locations[])
{
	if(curr_index == 0)
	{
		cout << endl << "Locations Used with the revenues in each locations" << endl;
		for(int i = 0; i < (MILES + 1); i++)
		{
			cout << setw(2) << locations_used[i] << " ";
		}
		cout << endl;
		cout << endl << "Locations Used with the advertisement in each locations" << endl;
		for(int i = 0; i < (MILES + 1); i++)
		{
			if(advertisement_in_locations[i] != 0)
			{
				cout << setw(1) << "x" << advertisement_in_locations[i] << " ";
			}
			else
			{
				cout << setw(2) << advertisement_in_locations[i] << " ";
			}
			
		}
		cout << endl;
	}
	else
	{
		if(used_billboards[curr_index - 1] == 1)
		{
			locations_used[x_array[curr_index - 1]] = r_array[curr_index - 1];
			advertisement_in_locations[x_array[curr_index - 1]] = curr_index;
		} 	
		printLocationsUsed(used_billboards, --curr_index, locations_used, x_array, r_array, advertisement_in_locations);
	}
}


int main()
{
	int n = POSSIBLE_SITES;							//possible_sites using the macro
	int D = MILES;									//total miles using the macro
	int x_array[n] = {6,7,12,14};					//the places where the billboards can be placed
	int r_array[n] = {5,6,5,1};						//revenue of the billboards
	int used_billboards[POSSIBLE_SITES] = {0};		//the auxiliary array to see which billboards are used	
	int max = 0;									//max revenue generated
	int locations_used[MILES + 1 ] = {0};			//used to display the locations used with the revenue in each location from advertisement
	int advertisement_in_locations[MILES + 1] = {0};//used to display which advertisement is in which location 

	billboard_optimize revenue_array[POSSIBLE_SITES + 1][MILES + 1] = {{0,0}}; 	//2darray of the struct used for optimization

	max = optimizeRevenue(0, x_array, r_array, revenue_array, used_billboards);
	
	cout << "Subproblems Dynamic Programming Table" << endl; 
	for(int i = 0; i < (POSSIBLE_SITES + 1); i++)
	{
		for(int j = 0; j < (MILES + 1); j++)
		{
			//cout << setw(3) << revenue_array[i][j].revenue << "," << revenue_array[i][j].index;
			cout << setw(2) << revenue_array[i][j].revenue << " " ;
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 0; i < POSSIBLE_SITES; i++)
	{	
		cout << "x" << i;
		if(used_billboards[i] == 1)
		{
			cout << " is used and the revenue is: " << r_array[i] << endl;
		}
		else
		{
			cout << " is not used and the revenue is: " << 0 << endl;
		}
	}
	cout << endl;


	cout << "The Maximum Revenue (Optimal Value) = " << max << endl << endl;
	
	//call the auxiliary functions to display part c and d.
	printAuxiliaryTable(used_billboards);
	printLocationsUsed(used_billboards, POSSIBLE_SITES, locations_used, x_array, r_array, advertisement_in_locations);

	return 0;
}


