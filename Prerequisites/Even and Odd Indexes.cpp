/*
Even and Odd Indexes
Send Feedback
Given an array of integers, print two integer values:
First, the sum of all numbers which are even as well as whose index are even.
Second, the sum of all numbers which are odd as well as whose index are odd.
Print the two integers space separated. (Arrays is 0-indexed)
Input:
Given an integer denoting the size of array.
Next line will have a line containing ‘n’ space separated integers.
Constraints:
1<=n<=10^5
1 <= Ai <= 10^6 
Output:
Two space separated integers denoting even and odd sums respectively.
Sample Input:
5
2 3 5 1 4
Sample Output:
6 4
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {cin>>a[i];}
    
    int sum1=0,sum2=0;
   for(int i=0;i<n;i++)
    {
        if(i%2==0 && a[i]%2==0)
            sum1=sum1+a[i];
        else if(i%2!=0 && a[i]%2!=0)
            sum2=sum2+a[i];
    }
    cout<<sum1<<" "<<sum2;
	return 0;
}
