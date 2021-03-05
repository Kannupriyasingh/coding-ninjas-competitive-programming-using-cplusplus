/*
Given two strings S and T with lengths M and N. Find and return the length of their shortest 'Super Sequence'.
 The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have both the given strings as its subsequences.
Note :
If the two strings do not have any common characters, then return the sum of the lengths of the two strings. 
Input Format:
The first only line of input contains a string, that denotes the value of string S. The following line contains a string, that denotes the value of string T.
Output Format:
Length of the smallest super-sequence of given two strings. 
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
ab
ac
Sample Output 1 :
3
Explanation of Sample Output 1 :
Their smallest super sequence can be "abc" which has length = 3.
Sample Input 2 :
pqqrpt
qerepct
Sample Output 2 :
9
*/


#include <bits/stdc++.h>

using namespace std;

int go(string s1, string s2, int i, int j, int** mem){
	int m = s1.size();
	int n = s2.size();

	//cout << m<<" "<<n << '\n';

	if (i > m-1)
	{
		return n-j;
	}

	if (j > n-1)
	{
		return m-i;
	}

	if (mem[i][j]!=-1)
	{
		return mem[i][j];
	}

	if (s1[i] == s2[j])
	{
		mem[i][j] = 1 + go(s1, s2, i+1, j+1, mem);
	}else{
		mem[i][j] = min(1+go(s1, s2, i+1, j, mem), 1+go(s1, s2, i, j+1, mem));
	}
    
return mem[i][j];
}

int smallestSuperSequencehelper(char str1[], int len1, char str2[], int len2) { 
  string s1 = "";
  string s2 = "";

  for (int i = 0; i < len1; ++i)
  {
  	s1 += str1[i];
  }

  for (int i = 0; i < len2; ++i)
  {
  	s2 += str2[i];
  }

  int** mem = new int*[len1+1];

  for (int i = 0; i < len1+1; ++i)
  {
  	mem[i] = new int[len2+1];
  	for (int j = 0; j < len2+1; ++j)
  	{
  		mem[i][j] = -1;
  	}
  }


  return go(s1, s2, 0, 0, mem);
}
int smallestSuperSequence(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    char str1[n1], str2[n2];
    for(int i = 0; s1[i] != '\0'; i++)
        str1[i] = s1[i];
    for(int i = 0; s2[i] != '\0'; i++)
        str2[i] = s2[i];
    
    int ans = smallestSuperSequencehelper(str1, n1, str2, n2);
    return ans;
    
}
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#include "solution.h"

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << smallestSuperSequence(str1, str2);
    return 0;
}
