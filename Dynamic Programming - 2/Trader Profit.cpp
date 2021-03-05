/*
Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
Input Format
The first line of input contains an integer q denoting the number of queries.

The first line of each test case contains a positive integer k, denoting the number of transactions. 

The second line of each test case contains a positive integer n, denoting the length of the array A.

The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
Constraints
1<=q<=100

0<k<10

2<=n<=30

0<=elements of array A<=1000
Output Format
For each query print the maximum profit earned by Mike on a new line. 
Sample Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25
Sample Output
87
1040
0
*/

/*#include <bits/stdc++.h>
using namespace std;
int helper(int *a, int n, int k, int ***dp, int ongoing)
{
    if(n == 0)
        return 0;
    if(dp[n][k][2] != -1)
        return dp[n][k][2];
    int option1, option2, option3;
    option1 = helper(a + 1, n - 1, k, dp, 0);
    if(ongoing == 1)
    {
        option2 = helper(a + 1, n - 1, k - 1, dp, 0) + a[0];
        dp[n][k][2] = max(option1, option2);
    }
    else if(ongoing == 0)
    {
        if(k > 0)
        {
            option3 = helper(a + 1, n - 1, k, dp, 1) - a[0];
            dp[n][k][2] = max(option1, option3);
        }
        else 
            return 0;
    }
    return dp[n][k][2];
    
    
}
int solve(int *a, int n, int k)
{
    int ***dp = new int**[n + 1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int*[k + 1];
        for(int j = 0; j <= k; j++)
        {
            dp[i][j] = new int[3];
            for(int l = 0; l <= 2; l++)
                dp[i][j][l] = -1;
        }
    }
    int ongoing = 0;
    int ans = helper(a,n,k,dp,0);
    for(int i = 0; i <= n; i++)
    {
     for(int j = 0; j <= k; j++)
            delete [] dp[i][j];
        delete [] dp[i];
    }
    delete [] dp;
    
    return ans;
}
int main()
{   int t;
    cin >> t;
 while(t--)
 {  int k;
  cin >> k;
    int n;
    cin >> n;
    int *arr = new int[n];
     for(int i = 0; i <= n; i++)
         cin >> arr[i];
     
     cout << solve(arr,n,k);
 }
    
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

int trading(int a[],int n,int k,int pro,int ** dp0,int**dp1){
    int ans1=0,ans2=0,ans3=0,ans4=0,ans=0;
    
    if(k==0 || n==0)
        return 0;
    if(pro==0){
        if(dp0[n][k]>-1)
            return dp0[n][k];
    }else{
        if(dp1[n][k]>-1)
            return dp1[n][k];
    }
    
    if(pro==0){
        ans1=trading(a+1,n-1,k,pro,dp0,dp1);
        ans2=trading(a+1,n-1,k,1,dp0,dp1)-a[0];
    }else{
        ans3=trading(a+1,n-1,k,pro,dp0,dp1);
        ans4=trading(a+1,n-1,k-1,0,dp0,dp1)+a[0];
    }
    ans=max(max(ans1,ans2),max(ans3,ans4));
    if(pro==0){
         dp0[n][k]=ans;
    }else{
        dp1[n][k]=ans;
    }
    return ans;
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int k=0,n=0;
        cin>>k>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int **dp0=new int *[n+1];
        for(int i=0;i<=n;i++)
            dp0[i]=new int[k+1];
            
        int **dp1=new int *[n+1];
        for(int i=0;i<=n;i++)
            dp1[i]=new int[k+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++)
                {
                    dp0[i][j]=-1;
                    dp1[i][j]=-1;
                }
        }
        cout<<trading(a,n,k,0,dp0,dp1)<<'\n';
    }
    return 0;
}
