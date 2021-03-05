/*
Nikunj loves donuts, but he also likes to stay fit. He eats n donuts in one sitting, and each donut has a calorie count, ci. After eating a donut with k calories, he must walk at least 2^j x k(where j is the number donuts he has already eaten) miles to maintain his weight.
Given the individual calorie counts for each of the n donuts, find and print a long integer denoting the minimum number of miles Nikunj must walk to maintain his weight. Note that he can eat the donuts in any order.
Input
The first line contains an integer, n, denoting the number of donuts. 
The second line contains n space-separated integers describing the respective calorie counts of each donut I, i.e ci.
Output
Print a long integer denoting the minimum number of miles Nikunj must walk to maintain his weight.
Constraints
1 ≤ n ≤ 40
1 ≤ ci ≤ 1000
Sample Input
3
1 3 2
Sample Output
11
*/

#include<bits/stdc++.h>
using namespace std;

long solve(int donut[], int donuts)
{
    long ans = 0;
    int power = 0;
    sort(donut, donut + donuts, greater<int>());
    for(int i = 0; i < donuts; i++)
    {
        long too_add = donut[i] * pow(2, power);
        ans += too_add;
        power++;
    }
    
    return ans;
}
int main()
{
    int donuts;
    cin >> donuts;
    int donut[donuts];
    for(int i = 0; i < donuts; i++)
        cin >> donut[i];
    cout<<solve(donut,donuts);
    
    return 0;
}
