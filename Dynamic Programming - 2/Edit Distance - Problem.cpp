/*
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/

#include <bits/stdc++.h>
using namespace std;

int helper(char *a, char *b, int n1, int n2, int **dp)
{
    if(n1 == 0 || n2 == 0)
    {
        if(n1 == 0)
            return n2;
        return n1;
    }
    
    if(dp[n1][n2] != -1)
        return dp[n1][n2];
    
    if(a[0] == b[0])
        dp[n1][n2] = helper(a+1,b+1,n1-1,n2-1,dp);
    else
    {
        int op1 = 1 + helper(a+1,b+1,n1-1,n2-1,dp); //substitution
        int op2 = 1 + helper(a,b+1,n1,n2-1,dp);//insert
        int op3 = 1 + helper(a+1,b,n1-1,n2,dp);//deleting
        dp[n1][n2] = min(op1, min(op2,op3));
    }
    return dp[n1][n2];
}
    
int editDistance(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    char a[n1];
    for(int i = 0; i < n1; i++)
        a[i] = s1[i];
    char b[n2];
    for(int i = 0; i < n2; i++)
        b[i] = s2[i];
    
    int **dp = new int*[n1+1];
    for(int i = 0; i <= n1; i++)
    {
        dp[i] = new int[n2 + 1];
        for(int j = 0; j <= n2; j++)
            dp[i][j] = -1;
    }
    int ans = helper(a,b,n1,n2,dp);
    for(int i = 0; i <= n1; i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
    
}


#include <iostream>
#include <cstring>
using namespace std;

#include "solution.h"

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}
