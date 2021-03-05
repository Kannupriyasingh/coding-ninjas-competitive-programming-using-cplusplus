/*
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the BFS Traversal, as described in the task.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/


/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(int **arr, int n, int e, int start_vertex, bool *visited)
{
   queue<int>q;
   q.push(start_vertex);
   visited[start_vertex] = true;
   while(!q.empty())
   {
       int current_vertex = q.front();
       q.pop();
       cout << current_vertex << " ";
       for(int i = 0; i < n; i++)
       {
           if(i == current_vertex)
           continue;
           
           if(arr[current_vertex][i] == 1 && !visited[i])
           {
               q.push(i);
               visited[i] = true;
           }
       }
   }
    //we have to check, is there any vertex which is not yet visited(in case of disconnected graph)
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
            print(arr,n,e,i,visited);
    }
        
}

int main()
{
    // n -> no_of_vertices, e -> no_of_edges
    int n,e;
    cin >> n >> e;
    int **arr = new int*[n]; //adjacency matrix
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
        {  
            arr[i][j] = 0;  //initially marked no edge between any two vertices
        }
    }
    
    //taking inputs of edges 
    for(int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start][end] = 1;  //marking the edge 
        arr[end][start] = 1;
    }
    
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    visited[i] = false;   //initially marking no vertex is visited
    
    
    //printing the graph
    print(arr, n, e, 0, visited);
    
    for(int i = 0; i < n; i++)
    delete [] arr[i];
    
    delete [] arr;
    delete [] visited;
    
    return 0;
}*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(int **arr, int n, int e, int start_vertex, bool *visited)
{
   queue<int>q;
   q.push(start_vertex);
   visited[start_vertex] = true;
   while(!q.empty())
   {
       int current_vertex = q.front();
       q.pop();
       cout << current_vertex << " ";
       for(int i = 0; i < n; i++)
       {
           if(i == current_vertex)
           continue;
           
           if(arr[current_vertex][i] == 1 && !visited[i])
           {
               q.push(i);
               visited[i] = true;
           }
       }
   }
}

int main()
{
    // n -> no_of_vertices, e -> no_of_edges
    int n,e;
    cin >> n >> e;
    int **arr = new int*[n]; //adjacency matrix
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
        {  
            arr[i][j] = 0;  //initially marked no edge between any two vertices
        }
    }
    
    //taking inputs of edges 
    for(int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start][end] = 1;  //marking the edge 
        arr[end][start] = 1;
    }
    
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    visited[i] = false;   //initially marking no vertex is visited
    
    
     //we have to check, is there any vertex which is not yet visited(in case of disconnected graph)
    for(int i=0;i<n;i++)
        if(!visited[i])
    		print(arr, n, e, i, visited);
    
    for(int i = 0; i < n; i++)
    delete [] arr[i];
    
    delete [] arr;
    delete [] visited;
    
    return 0;
}












































/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int start_vertex, bool *visited, queue<int>q)
{
   // cout << start_vertex << " ";
    for(int i = 0; i < n; i++)
    {
        if(visited[start_vertex] = false)
        {
            q.push(start_vertex);
            visited[start_vertex] = true;
            
            for(int j = 0; j < n; j++)
            {
                if(edges[start_vertex][j] == 1)
                {
                    q.push(j);
                    visited[j] = true;
                }
                
            }
        }
        else
            continue;
        cout << q.front() << " ";
        q.pop();
        print(edges,n,q.front(),visited,q);
    }
}

int main() {
    int n, e;
    cin >> n >>e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    
    for(int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
    queue<int>q;
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    print(edges, n, 0, visited,q);
    
}*/
