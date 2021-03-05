/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274
*/

long staircase(int n)
{
   long long int *output = new long long int[n + 1];
    output[0] = output[1] = 1;
    output[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        output[i] = output[i - 1] + output[i - 2] + output[i - 3];
    }
    return output[n];
}
#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
