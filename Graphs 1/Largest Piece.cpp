/*
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/

/*#include <iostream>
using namespace std;
int count_ones(int **arr, int n, int i, int j, bool **visited)
{
    int count = 1;
    if (i > 0 && !visited[i - 1][j] && arr[i - 1][j] == 1) //up
    {
        visited[i - 1][j] = true;
        count += count_ones(arr, n, i - 1, j, visited);
    }
    if (j > 0 && !visited[i][j - 1] && arr[i][j - 1] == 1) //left
    {
        visited[i][j - 1] = true;
        count += count_ones(arr, n, i, j - 1, visited);
    }
    if (i < n - 1 && !visited[i + 1][j] && arr[i + 1][j] == 1) //down
    {
        visited[i + 1][j] = true;
        count += count_ones(arr, n, i + 1, j, visited);
    }
    if (j < n - 1 && !visited[i][j + 1] && arr[i][j + 1] == 1) //right
    {
        visited[i][j + 1] = true;
        count += count_ones(arr, n, i, j + 1, visited);
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int>>cake, int n)
{
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = cake[i][j] - '0';
        }
    }

    int maximum = 0;
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                visited[i][j] = true;
                int current_maximum = count_ones(arr, n, i, j, visited);
                if (current_maximum > maximum)
                {
                    maximum = current_maximum;
                }
                for (int p = 0; p < n; p++)
                {
                    for (int q = 0; q < n; q++)
                    {
                        visited[p][q] = false;
                    }
                }
            }
        }
    }
    return maximum;
}*/
int DFS(vector<vector<int>> &arr, int N, int i, int j, bool** visited){
    if( (i>N-1) || (i<0) || (j>N-1) || (j<0) ){
        return 0;
    }

    if(arr[i][j] == 1 && !visited[i][j]){
        visited[i][j] = 1;
        // recurse on up, down, left, right
        int ans = 1 + DFS(arr, N, i+1, j, visited) + DFS(arr, N, i-1, j, visited) + DFS(arr, N, i, j+1, visited) + DFS(arr, N, i, j-1, visited);
        return ans;
    }

    return 0;
}

int getBiggestPieceSize(vector<vector<int>> &arr, int N) {
    bool** visited = new bool*[N];
    for(int i=0; i<N; i++){
        visited[i] = new bool[N]();
    }

    int maxCount = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                maxCount = max(maxCount, DFS(arr, N, i, j, visited));
            }
        }
    }

    return maxCount;
}
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}
