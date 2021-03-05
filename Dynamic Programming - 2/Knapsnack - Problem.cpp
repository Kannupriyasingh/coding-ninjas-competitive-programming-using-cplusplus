/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/


/*int helper(int* weights, int* values, int n, int maxWeight, int **dp)
{
    if(maxWeight == 0 || n == 0)
        return 0;
    if(dp[n][maxWeight] != -1)
        return dp[n][maxWeight];
    if(weights[0] <= maxWeight)
        dp[n][maxWeight] = max(values[0] + helper(weights+1,values+1,n-1,maxWeight-weights[0],dp), helper(weights+1,values+1,n-1,maxWeight,dp));
    else
        dp[n][maxWeight] =  helper(weights+1,values+1,n-1,maxWeight,dp);
    
    return dp[n][maxWeight];
}

int knapsack(int* weights, int* values, int n, int maxWeight){

 int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight+1];
        for(int j = 0; j <= maxWeight; j++)
            dp[i][j] = -1;
    }
 int ans = helper(weights,values,n,maxWeight,dp);
     for(int i = 0; i <= n; i++)
         delete [] dp[i];
    delete [] dp;
return ans;        

}*/
int knapsack(int* weights, int* values, int n, int maxWeight)
{
    int **dp = new int*[2];
    for(int i = 0; i <= 1; i++)
    {
        dp[i] = new int[maxWeight + 1];
    }
    for(int i = 0; i <= maxWeight; i++)
        dp[0][i] = 0;
    
    int flag = 1;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= maxWeight; j++)
        {
            if(j >= weights[i - 1])
                dp[flag][j] = max(values[i - 1] + dp[flag ^ 1][j - weights[i - 1]], dp[flag ^ 1][j]);
            else
                dp[flag][j] = dp[flag ^ 1][j];
        }
        flag =  flag ^ 1;
    }
    return dp[flag ^ 1][maxWeight];
}


#include <cstring>
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}


















/*#include<bits/stdc++.h> 
using namespace std;  
int knapsack(int *wt, int *val, int n, int W) 
{ 
	// matrix to store final result 
	int mat[2][W+1]; 
	memset(mat, 0, sizeof(mat)); 

	// iterate through all items 
	int i = 0; 
	while (i < n) // one by one traverse each element 
	{ 
		int j = 0; // traverse all weights j <= W 

		// if i is odd that mean till now we have odd 
		// number of elements so we store result in 1th 
		// indexed row 
		if (i%2!=0) 
		{ 
			while (++j <= W) // check for each value 
			{ 
				if (wt[i] <= j) // include element 
					mat[1][j] = max(val[i] + mat[0][j-wt[i]], 
									mat[0][j] ); 
				else		 // exclude element 
					mat[1][j] = mat[0][j]; 
			} 

		} 

		// if i is even that mean till now we have even number 
		// of elements so we store result in 0th indexed row 
		else
		{ 
			while(++j <= W) 
			{ 
				if (wt[i] <= j) 
					mat[0][j] = max(val[i] + mat[1][j-wt[i]], 
									mat[1][j]); 
				else
					mat[0][j] = mat[1][j]; 
			} 
		} 
		i++; 
	} 

	// Return mat[0][W] if n is odd, else mat[1][W] 
	return (n%2 != 0)? mat[0][W] : mat[1][W]; 
} */




