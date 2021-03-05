/*
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= N <= 1000
1 <= M <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/

#include <bits/stdc++.h>

using namespace std;

int solve(string s1,string s2)
{
	int m =s1.size();
	int n =s2.size();

	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for (int i = 0; i < n+1; ++i)
	{
		dp[m][i] = n-i;
	}

	for (int i = 0; i < m+1; ++i)
	{
		dp[i][n] = m-i;
	}

	for (int i = m-1; i >= 0; --i)
	{
		for (int j = n-1; j >= 0; --j)
		{
			int k = j;
			
			while(k<s2.size())
			{
				if(s2[k]==s1[i])
				{
					break;
				}
				k++;
			}
			if (k==s2.size())
			{
				dp[i][j] = 1;
				//return 1;
			}

			int c1 = 1+dp[i+1][k+1];
			int c2 = dp[i+1][j];

			dp[i][j] = min(c1, c2);
		}
	}

	return dp[0][0];


}
#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
