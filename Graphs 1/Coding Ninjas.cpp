/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/

/*#include<iostream>
#define MAXN 1000
using namespace std;
bool checker (vector<vector<char>>arr, int n, int m, int i, int j, string s, bool**visited)
{
	if (s.length() == 0)
	{
		return true;
	}
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return false;
	}
	int row_array[] = { i - 1, i, i + 1 };
	int col_array[] = { j - 1, j, j + 1 };
	for (int p = 0; p < 3; p++)
	{
		for (int q = 0; q < 3; q++)
		{
			if (row_array[p] == i && col_array[q] == j)
			{
				continue;
			}

			int row = row_array[p];
			int col = col_array[q];
			if (row < 0 || col < 0 || row >= n || col >= m)
			{
				continue;
			}
			if (arr[row][col] == s[0] && !visited[row][col])
			{
				visited[row][col] = true;
				bool checked = checker(arr, n, m, row, col, s.substr(1), visited);
				if (checked)
				{
					return checked;
				}
				else
				{
					visited[row][col] = false;
				}
			}
		}
	}
	return false;
}




int hasPath(vector<vector<char>> arr,int n, int m)
{
    
    bool** visited = new bool* [n];
    for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
    
    
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'C')
			{
                //creating dynamic boolean 2d array
				
                
                //checking
				if(checker(arr, n, m, i, j, "ODINGNINJA", visited))
				{
					return 1;
				}
                
                //deleting dynamic boolean array
				for(int p=0; p<n; p++)
                {
                    for(int q=0; q<m; q++)
                    {
                        visited[p][q]=false;
                    }
                }
			}
		}
	}
	return 0;
}*/

int validPoint(int x, int y, int n, int m) { 
    return (x >= 0 && x < n && y >= 0 && y < m); 
} 
bool dfs(vector<vector<char>> &board, vector<vector<bool>> &used, string &word, int x, int y, int wordIndex, int n, int m) { 
    if (wordIndex == 11) { 
        return true; 
    } 
    used[x][y] = true; 
    bool found = false; 
    int dXdY[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; 
    for (int i = 0; i < 8; ++i) { 
        int newX = x + dXdY[i][0]; 
        int newY = y + dXdY[i][1]; 
        if (validPoint(newX, newY, n, m) && board[newX][newY] == word[wordIndex] && !used[newX][newY]) { 
            found = found | dfs(board, used, word, newX, newY, wordIndex + 1, n, m); 
        }
    } 
    used[x][y] = false;
    return found; 
} 
bool hasPath(vector<vector<char>> &board, int n, int m) { 
    bool foundPath = false; 
    string word = "CODINGNINJA"; 
    vector<vector<bool>> used(n, vector<bool>(m, false)); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (board[i][j] == word[0]) { 
                foundPath = dfs(board, used, word, i, j, 1, n, m); 
                if (foundPath) break; 
            } 
        } 
        if (foundPath) break; 
    } 
    return foundPath; 
}
