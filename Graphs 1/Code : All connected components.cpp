/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/


/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int **edge, int v, int start_vertex, bool *visited,vector<vector<int>>&answer)
{
    
    vector<int>ans;
    int count = 1;
    ans.push_back(start_vertex);
        visited[start_vertex] = true;
        while(count != v)
        {
            int current_vertex;
            for(int i = 0; i < v; i++)
            {
                if(visited[i] == false)
                {
                    current_vertex = i;
                    break;
                }
            }
            for(int i = 0; i < v; i++)
            {
                if(edge[current_vertex][i] == 1 && visited[i] == false)
                {
                    visited[i] = true;
                    ans.push_back(i);
                    count++;
                }
            }
            answer.push_back(ans);
            ans.clear();
            
                
        }
    
    
}

int main() {
    int v,e;
    cin >> v >> e;
    int **edge = new int*[v];
    for(int i = 0; i < v; i++)
    {
        edge[i] = new int[v];
        for(int j = 0; j < v; j++)
            edge[i][j] = 0;
    }
    
    for(int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        edge[start][end] = 1;
        edge[end][start] = 1;
    }
    
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
    
    vector<vector<int>>answer;
    solve(edge,v,0,visited,answer);
    
for(int i = 0; i < answer.size(); i++)
    cout << answer[i] << endl;
}*/





#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vector_creator(int** arr, int n, int starting_vertex, bool* visited)
{
	vector<int>temp;
	queue<int> q;
	q.push(starting_vertex);
	visited[starting_vertex] = true;
	while (!q.empty())
	{
		temp.push_back(q.front());
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
	return temp;
}
int main()
{
	int v, e;
	cin >> v >> e;
	int** arr = new int* [v];
	for (int i = 0; i < v; i++)
	{
		arr[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			arr[i][j] = 0;
		}
	}
	while (e--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	vector<vector<int> >super;
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			super.push_back(vector_creator(arr, v, i, visited));
		}
	}
	for (int i = 0; i < super.size(); i++)
	{
		sort(super[i].begin(), super[i].end());
		for (int j = 0; j < super[i].size(); j++)
		{
			cout << super[i][j]<<" ";
		}
		cout << endl;
	}
}
