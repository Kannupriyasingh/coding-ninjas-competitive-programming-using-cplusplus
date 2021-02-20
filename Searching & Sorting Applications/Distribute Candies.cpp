/*
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
Output
For each test case print the required answer in a seperate line.
Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9
Sample Output:
3
9
*/

#include<bits/stdc++.h>
using namespace std;


bool solve(int a[],int n, int k, int guess)
{   int count = 0;
    for(int i = 0; i < n; i++)
    {
        count = count + a[i]/guess;
         if(count >= k)
        return true;
    }
        
 return false;
}
int binary_search(int a[], int n, int k)
{   int ans = INT_MIN;
    int i = 0;
    int j = a[n-1];
    while(i < j)
    {
        int mid = (i + j)/2;
        if(solve(a,n,k,mid))
        {  ans= max(ans,mid);
            i = mid + 1;
        }
        else 
            j = mid;
    }
 return ans;
}

int main() {

   int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a,a+n);
        if(k==1)
            cout<<a[n-1];
        else
            cout<<binary_search(a,n,k)<<endl;
    }
}
