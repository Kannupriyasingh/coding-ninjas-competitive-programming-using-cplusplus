/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/

#define mod 1000000007
int countBST(int n) 
{ 

	// DP to store the number of unique BST with key i 
	long long int dp[n + 1] = {0}; 
//	fill_n(dp, n + 1, 0); 

	// Base case 
	dp[0] = 1; 
	dp[1] = 1; 

	// dp table filling in top-down approach. 
	for (int i = 2; i <= n; i++) { 
		for (int j = 1; j <= i; j++) { 

			// n-i in right * i-1 in left 
			//dp[i] = dp[i] + (dp[i - j] * dp[j - 1]); 
            dp[i] = (dp[i] + (dp[i - j] * dp[j - 1])%mod)%mod; 
		} 
	} 
  // long long int ans = dp[n] % mod;
	return dp[n]; 
} 

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#include "solution.h"




int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
