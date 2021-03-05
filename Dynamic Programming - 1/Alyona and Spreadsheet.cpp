/*
During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
Alyona is too small to deal with this task and asks you to help!
Input
The first line of the input contains two positive integers n and m (1 ≤ n·m ≤ 100 000) — the number of rows and the number of columns in the table respectively. Note that your are given a constraint that bound the product of these two integers, i.e. the number of elements in the table.

Each of the following n lines contains m integers. The j-th integers in the i of these lines stands for ai, j (1 ≤ ai, j ≤ 109).

The next line of the input contains an integer k (1 ≤ k ≤ 100 000) — the number of task that teacher gave to Alyona.

The i-th of the next k lines contains two integers li and ri (1 ≤ li ≤ ri ≤ n).
Output
Print "Yes" to the i-th line of the output if the table consisting of rows from li to ri inclusive is sorted in non-decreasing order in at least one column. Otherwise, print "No".
Sample Input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5
Sample Output
Yes
No
Yes
Yes
Yes
No
*/



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k,i,j,x=INT_MAX,z,s,q,l,r;
    cin>>n>>m;
    int a[n+2][m+2],dp[n+2][m+2]={0};
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
            dp[1][j]=1;
        }
    }
    for(i=1;i<=m;i++)//SO IN DP ARRAY FOR EVERY DP[I][J] WE ARE TRYING TO STORE THE INDEX OF
    {//OF UPPER ROW FROM WHERE TILL J'TH INDEX THE VALUES IN COLUMN VERTICALLY ARE IN 
        //ASCENDING ORDER
        for(j=2;j<=n;j++)
        {
            if(a[j][i]>=a[j-1][i])
            {
                dp[j][i]+=dp[j-1][i];
            }
            else
            {
                dp[j][i]=j;
            }
        }
    }
    int row[n+2]={0};
   /* for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<"   "; 
        }
        cout<<endl;
    }*/
    for(i=1;i<=n;i++)//NOW WE KNOW THAT QUERIES WILL BE 2 ROWS INDEXES SO WE WILL
        //CLCULATE THE MIN OF EACH ROW AND STORE IN A PARTICULAR ARRAY
    {
        x=INT_MAX;
        for(j=1;j<=m;j++)
        {
             if(dp[i][j]<x)
                 x=dp[i][j];
        }
        row[i]=x;
    }
    /*for(i=1;i<=n;i++)
    {
        cout<<row[i]<<" ";
    }
    cout<<endl;*/
    cin>>q;
    while(q--)//NOW FOR EACH [L,R] WE WILL GO TO R'TH INDEX AND CHECK WHETHER L IS  GREATER 
        //THAN ROW[R] 
    {
        cin>>l>>r;
        if(l>=row[r])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
