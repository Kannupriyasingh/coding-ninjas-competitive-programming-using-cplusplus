/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/

#include<bits/stdc++.h>
using namespace std;

struct times
{
    int start_time, finish_time;
};
bool compare(times a, times b)
{    
     bool ans = (a.finish_time < b.finish_time);
    return ans;
}

int solve(int n, times arr[])
{
    sort(arr, arr + n, compare);
    int count = 1, i = 0;
    for(int j = 1; j < n; j++)
    {
        if(arr[i].finish_time <= arr[j].start_time)
        {
            count++;
            i = j;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    times arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i].start_time >> arr[i].finish_time;
    
    cout << solve(n,arr);
    return 0;
}
