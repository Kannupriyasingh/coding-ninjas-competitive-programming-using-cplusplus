/*
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
    unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format
The first line contains an integer N.
The second line contains an integer K.
N lines follow each integer containing the candy in the ith packet.
Output Format
A single integer which will be minimum unfairness.
Constraints
2<=N<=10^5

2<=K<=N

0<= number of candies in each packet <=10^9
Sample Input
7
3
10
100
300
200
1000
20
30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll n,m,k,i,j,x,z=0;
    cin>>n;
    cin>>k;
    ll a[n+1];
    ll presum[n+2]={0};
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
   /* for(i=1;i<=n;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;*/
    presum[1]=a[1];
    for(i=2;i<=n;i++)
    {
        presum[i]=presum[i-1]+a[i];
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<presum[i]<<"  ";
    }
    cout<<endl;*/
    ll ksum[n+2];
    ksum[1]=0;ksum[2]=a[2]-a[1];
    z=ksum[2];
    for(i=2;i<k;i++)
    {
        z+=i*a[i+1] - presum[i];
    }
    //cout<<"z: "<<z<<endl;
    x=1;
    ll cost=z;
    ll mini=z;
    for(i=k+1;i<=n;i++)
    {
        cost=cost-2*(presum[i-1]-presum[x]) + (k-1)*a[x] + (k-1)*a[i];
       // cout<<cost<<"   "; 
        if(cost<mini)
            mini=cost;
        x++;
       
    }
    //cout<<endl;
    cout<<mini<<endl;
    return 0;
    
}
