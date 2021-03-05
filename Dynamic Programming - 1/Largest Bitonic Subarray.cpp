/*
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2

*/

/*int longestBitonicSubarray(int *input, int n) {
	int inc[n];
        int dec[n];
        int i,max;
        inc[0] = 1;
        dec[n - 1] = 1;
        for(i = 1; i < n; i++)
        {
            if(input[i] >= input[i - 1])
            inc[i] = inc[i - 1] + 1;
            else
            inc[i] = 1;
            
        }
        
        for(i = n - 2; i >= 0; i--)
        {
             if(input[i] >= input[i + 1])
             dec[i] = dec[i + 1] + 1;
             else
             dec[i] = 1;
             
        }
        
        max = inc[0] + dec[0] - 1;
        for(i = 1; i < n; i++)
        if(inc[i] + dec[i] - 1 > max)
        max = inc[i] + dec[i] - 1;
     	
     	
     	return max;
     	
 	}*/
/*int longestBitonicSubarray(int *input, int n)
{
    if(n == 0)
        return 0;
    int maxlen = 1;
    int start = 0;
    int nextstart = 0;
    int j = 0;
    while(j < n - 1)
    {
        while(j<n-1 && input[j] <= input[j + 1])
            j++;
        while(j<n-1 && input[j] >= input[j + 1])
        {
            if(j<n-1 && input[j] > input[j+1])
                nextstart = j + 1;
            
            j++;
        }
        maxlen = max(maxlen, j - (start - 1));
        start = nextstart;
    }
    return maxlen;
}*/
int longestBitonicSubarray(int *input, int n)
{
    int i,j;
    int *lis = new int[n];
    for(i = 0; i < n; i++)
        lis[i] = 1;
    
    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++)
            if(input[i] > input[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    
    int *ids = new int[n];
    for(i = 0; i < n; i++)
        ids[i] = 1;
    
    for(i = n-2; i >= 0; i--)
        for(j = n-1; j > i; j--)
            if(input[i] > input[j] && ids[i] < ids[j] + 1)
                ids[i] = ids[j] + 1;
    int max = lis[0] + ids[0] - 1;
    for(i = 1; i < n; i++)
    {
        if(lis[i] + ids[i] - 1 > max)
            max = lis[i] +ids[i] - 1;
    }
    return max;
}


#include<iostream>
using namespace std;
#include "solution.h"

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
