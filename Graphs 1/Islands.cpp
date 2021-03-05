/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void visited_filler(int** arr, int n, int starting_vertex, bool* visited)
{
	queue<int> q;
	q.push(starting_vertex);
	visited[starting_vertex] = true;
	while (!q.empty())
	{
		int current_element = q.front();
		for (int i = 1; i < n; i++)
		{
			if (i == current_element)
			{
				continue;
			}
			if (visited[i])
			{
				continue;
			}
			if (arr[current_element][i] == 1)
			{
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
	}
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
    int** arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
    
    for (int i = 0; i < m; i++)
	{
		arr[u[i]][v[i]] = 1;
		arr[v[i]][u[i]] = 1;
	}
    
    bool* visited = new bool[n+1];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
    
    int count=0;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
		    visited_filler(arr, n+1, i, visited);
            count+=1;
		}
	}
	return count;
}

int main()
{

	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		u.push_back(x);
        v.push_back(y);
        
    }
	
	cout<<solve(n,m,u,v)<<endl;

}
