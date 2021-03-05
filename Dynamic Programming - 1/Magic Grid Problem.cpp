/*
You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. You have to find the minimum number of strength points with which you will be able to reach the destination cell.
Input format:
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with A[i][j] < 0 contain poison, others contain magic juice.
Output format:
Output T lines, one for each case containing the minimum strength you should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).
Constraints:
1 ≤ T ≤ 5
2 ≤ R, C ≤ 500
-10^3 ≤ A[i][j] ≤ 10^3
A[1][1] = A[R][C] = 0
Time Limit: 1 second
Sample Input 1:
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0
Sample Output 1:
2
1
2
*/


/*#include <bits/stdc++.h>
using namespace std;
int solve(int startx , int starty , int n, int m, int a[][m])
{
    int **output = new *int[n];
    for(int i = 0; i < n; i++)
    {
        output[i] = new int[m];
    }
    output[n-1][m-1] = output[n-2][m-1] = output[n-1][m-2] = 1;
    for(int i = n - 2; i >= 0; i--)
        output[i][m - 1] = a[i][m - 1] - output[i + 1][m - 1];
    for(int j = m - 2; j >= 0; j--)
        output[n - 1][j] = a[n - 1][j] - output[n - 1][j + 1];
    
    for(int i = n - 2; i >= 0; i--)
        for(int j = m - 2; j >= 0; j--)
            output[i][j] = a[i][j] - max(output[i+1][j], output[i][j+1]);
    
    return output[0][0];
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        cout<<solve(0,0,n,m,a)<<endl;
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int **a)
{
    int **output = new int*[n];
    /*for(int i = 0; i <= n; i++)
    {
        output[i] = new int[m];
         for(int j = 0; j <= m; j++)
        output[i][j] = -1;
    }*/
    for(int i = 0; i < n; i++)
    {
        output[i] = new int[m];
    }
    output[n-1][m-1] = 1;
    for(int i = n - 2; i >= 0; i--)
        output[i][m - 1] = output[i + 1][m - 1] - a[i][m-1];
    for(int j = m - 2; j >= 0; j--)
        output[n - 1][j] = output[n - 1][j + 1] - a[n-1][j];
    
    for(int i = n - 2; i >= 0; i--){
        for(int j = m - 2; j >= 0; j--){
            output[i][j] = min(output[i+1][j] - a[i][j], output[i][j+1] - a[i][j]);
            if(output[i][j] <= 0)
                output[i][j] = 1;
        }
    }
    
    return output[0][0];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int **a = new int*[n];
        for(int i = 0; i < n; i++){
            a[i] = new int[m];
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        
        cout<<solve(n,m,a)<<endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int **grid = new int *[n];

        for (int i = 0; i < n; ++i) {
            grid[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << getMinimumStrength(grid, n, m) << "\n";

        for (int i = 0; i < n; ++i) {
            delete[] grid[i];
        }

        delete[] grid;
    }
}
