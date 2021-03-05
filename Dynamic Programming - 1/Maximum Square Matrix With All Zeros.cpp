/*
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
*/


/*#include<bits/stdc++.h>
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int array[row][col];
    for(int i = 0; i < row; i++)
    { 
        if(arr[i][0] == 0)
            array[i][0] = 1;
        else
            array[i][0] = 0;
    }
            
    
    for(int i = 0; i < col; i++)
    {  
        if(arr[0][i] == 0)
            array[0][i] = 1;
        else
            array[0][i] = 0;
    }
    
    for(int i = 1; i < row; i++)
        for(int j = 1; j < col; j++)
        {
            if(arr[i][j] == 0)
            {
                int num = min(array[i-1][j-1], min(array[i-1][j],array[i][j-1])) + 1;
                //int num1 = std::min(array[i][j-1],array[i-1][j]);
                //int num2 = std::min(num1,array[i-1][j-1]);
                //array[i][j] = num2 + 1;
                array[i][j] = num;
            }
            else
                array[i][j] = 0;
        }
    int ans = INT_MIN;
     for(int i = 1; i < row; i++)
        for(int j = 1; j < col; j++)
            ans = std::max(ans,array[i][j]);
    
    return ans;
}*/
// C++ code for Maximum size square 
// sub-matrix with all 1s 
#include <bits/stdc++.h> 
#define bool int 
using namespace std; 


int findMaxSquareWithAllZeros(int** arr, int row, int col)
{ 
	int i,j; 
	int S[row][col]; 
	int max_of_s, max_i, max_j; 
	
	/* Set first column of S[][]*/
	for(i = 0; i < row; i++) 
		S[i][0] = !(arr[i][0]); 
	
	/* Set first row of S[][]*/
	for(j = 0; j < col; j++) 
		S[0][j] = !(arr[0][j]); 
		
	/* Construct other entries of S[][]*/
	for(i = 1; i < row; i++) 
	{ 
		for(j = 1; j < col; j++) 
		{ 
			if(arr[i][j] == 0) 
				S[i][j] = min(S[i][j-1],min( S[i-1][j], 
								S[i-1][j-1])) + 1; 
			else
				S[i][j] = 0; 
		} 
	} 
	
	/* Find the maximum entry, and indexes of maximum entry 
		in S[][] */
	max_of_s = S[0][0]; 
	for(i = 0; i < row; i++) 
	{ 
		for(j = 0; j < col; j++) 
		{ 
			if(max_of_s < S[i][j]) 
			{ 
				max_of_s = S[i][j]; 
				
			} 
		}			 
	} 
    return max_of_s;

} 

#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
