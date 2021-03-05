/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
    ll n,m1,l,r,q,x;
    cin>>n;
    ll arr[n+2];
    memset(arr,0,sizeof(arr));
    cin>>m1;
    while(m1--){
        cin>>l>>r;
        arr[l]+=1;
        arr[r+1]-=1;
    }
    for(ll i=2;i<=n;i++)
        arr[i]=arr[i]+arr[i-1];
    ll m[n+1]={0};
    for(ll i=1;i<=n;i++)
        m[arr[i]]++;
    for(ll i=n-1;i>=1;i--){
        m[i]=m[i]+m[i+1];
    }
    
    cin>>q;
    while(q--){
        cin>>x;
        cout<<m[x]<<endl;
    }
}
