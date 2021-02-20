/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3 
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.
*/

#include<bits/stdc++.h>
using namespace std;

bool solve(long long int a[], int n, int cow , long long int guess)
{
    long long int previous_stall = 0;
    long long int stall = 1;
    for(int i = 1; i <= cow-1; i++)
    {
        while(a[stall] - a[previous_stall] < guess)
        {
            stall++;
        if(stall == n)
            return false;
        }
    previous_stall = stall;
    }
    return true;

}
long long int maxcount(long long int a[], int n, int c)
{
    long long int low = 0;
    //long long int high = a[n - 1]/c;
    long long int high = a[n - 1] - a[0];
    long long int longestcount = 0;
    while(low <= high)
    {
        long long int mid = low + (high - low)/2;
        if(solve(a,n,c,mid))
        {
            low = mid + 1;
            longestcount = max(mid, longestcount);
        }
        else
            high = mid - 1;
    }
    return longestcount;
}
int main() {

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int c;
        cin >> n >> c;
        long long int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
         sort(arr, arr + n);
        cout<<maxcount(arr,n,c)<<endl;
        
    }
}
/*
bool solve(long long a[], int n, int cows , long long dist)
{
    cows--;
    int k = 0;
    for(int i=1;i<n && cows!=0;i++)
    {
        if(a[i]-a[k]>=dist)
        {
            cows--;
            k=i;
        }
    }
    if(cows == 0)
    {
        return true;
    }
    return false;

}
long long maxcount(long long int a[], int n, int c)
{
    long long low = 0;
    long long high = a[n - 1] - a[0];
    long long longestcount = 0;
    while(low <= high)
    {
        long long mid = low + (high - low)/2;
        if(solve(a,n,c,mid))
        {
            low = mid + 1;
            longestcount = mid;
        }
        else
            high = mid - 1;
    }
    return longestcount;
}
int main() {

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int c;
        cin >> n >> c;
        long long arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr,arr+n);
        cout<<maxcount(arr,n,c)<<endl;
    }
}*/
