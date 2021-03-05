/*
Given two strings, S and T with lengths M and N, find the length of the 'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the length of the 'Longest Common Subsequence'.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1sec
Sample Input 1 :
adebc
dcadb
Sample Output 1 :
3
Explanation of the Sample Input 1 :
Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 
Sample Input 2 :
ab
defg
Sample Output 2 :
0
Explanation of the Sample Input 2 :
The only subsequence that is common to both the given strings is an empty string("") of length 0.
*/


#include<bits/stdc++.h>
int lcs(string s1, string s2)
{
  // int m = strlen(s1);
   //int n = strlen(s2);
    int m = s1.size();
    int n = s2.size();
   int **t = new int*[m + 1];
    for(int i = 0; i <= m; i++)
    {
        t[i] = new int[n + 1];
    }
    for(int i = 0; i <= m; i++)
        t[i][0] = 0;
    for(int i = 0; i <= n; i++)
        t[0][i] = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s1[m - i] == s2[n - j])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    int ans = t[m][n];
    for(int i = 0; i <= m; i++)
        delete [] t[i];
    
    delete [] t;
    return ans;
}

#include<iostream>
#include<cstring>
using namespace std;

#include "solution.h"

int main()
{
	string s; 
	string t;

	cin >> s;
	cin >> t;

	cout << lcs(s, t) << endl;
}
