/*
Anandi and Jagya were getting married again when they have achieved proper age. Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings. Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. But he can give only one blessing of K length because some priest told him to do so. Thus he decides to generate a blessing using the other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has. Happiness of the blessing he generates is calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum. If he is not able to generate a common subsequence of length K then the happiness is 0 (zero). Alok Nath comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has.
Input Specification
First line consists of number of test cases t. Each test case consists of two strings b1 (blessing 1),b2 (blessing 2) and an integer K, each of them in separate lines.
Output Specification
Output consists of t lines each containing an integer denoting the maximum happiness value that can be generated by the two blessings.
Constraint
1 <= t <= 50

1 <= length(b1) , length(b2) <= 100 

1 <= K <= 100
Sample Input
2
asdf
asdf
3
anandi
jagya
3
Sample Output
317
0
*/


/*#include <bits/stdc++.h>
using namespace std;
//this is working for some testcases
string solve(string s1, string s2, int& lcs, string &s)
{   string str = "";
    int n1 = s1.size();
    int n2 = s2.size();
    int **dp = new int*[n1+1];
    for(int i = 0; i <= n1; i++)
    {
        dp[i] = new int[n2+1];
    }
    for(int i = 0; i <= n1; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= n2; i++)
        dp[0][i] = 0;
    
    for(int i = 1; i <= n1; i++)
        for(int j = 1; j <= n2; j++)
        {
            if(s1[n1-i] == s2[n2-j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                str.push_back(s1[n1-i]);
            }
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    int ans = dp[n1][n2];
    for(int i = 0; i <= n1; i++)
        delete [] dp[i];
    
    delete [] dp;
// cout<<str<<endl;
// str = s;
 lcs = ans;
 return str;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {   int lcs;
        string s;
     int sum = 0;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        int k;
        cin >> k;
    s = solve(s1,s2,lcs,s);
         if(lcs < k)
            cout<<"0"<<endl;
        else 
        {  int n = s.size();
            sort(s.begin(),s.end(),greater<char>());
            for(int i = 0; i < k; i++)
            {
                char c = s[i];
                 int val = int(c);
                sum+=val;
            }
         cout<<sum<<endl;
        }
        
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int helper(char* a,char *b,int m,int n,int k,int*** dp)
{
    if(k==0) return 0;
    if(m==0 || n==0) return INT_MIN;

    if(dp[m][n][k]!=-1)
    {
        return dp[m][n][k];
    }
    else
    {
        int ans;

        if(a[0]!=b[0])
        {
            int op1 = helper(a+1,b,m-1,n,k,dp);
            int op2 = helper(a,b+1,m,n-1,k,dp);

            ans = max(op1,op2);

        }
        else ///if(a[0]==b[0])
        {
            int op1 = (int)(a[0]) + helper(a+1,b+1,m-1,n-1,k-1,dp);
            int op2 = helper(a+1,b,m-1,n,k,dp);
            int op3 = helper(a,b+1,m,n-1,k,dp);

            ans = max(op1,max(op2,op3));
        }
        dp[m][n][k] = ans;
        return ans;
    }



}
int solve(string s1,string s2,int length_of_subseq)
{
 	int m = s1.length();
    int n = s2.length();

    char a[m];
    for(int i=0;i<m;i++)
    {
        a[i]=s1[i];
    }

    char b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=s2[i];
    }

    int ***dp = new int**[m+1];
    for (int i=0;i<m+1; i++)
    {
        dp[i] = new int*[n+1];
        for (int j=0; j<n+1; j++)
        {
            dp[i][j] = new int[length_of_subseq+1];
            for(int k=0;k<length_of_subseq+1;k++)
            {
                dp[i][j][k] = -1;
            }
        }

    }

    int ans = helper(a,b,m,n,length_of_subseq,dp);
    if(ans<0) ans=0;

    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            delete [] dp[i][j];
        }
        delete [] dp[i];
    }
    delete [] dp;

    return ans;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        cin>>s1;

        string s2;
        cin>>s2;

        int length_of_subseq;
        cin>>length_of_subseq;

        cout<<solve(s1,s2,length_of_subseq)<<endl;
    }
}
