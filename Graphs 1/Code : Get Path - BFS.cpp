/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
map<int, int>data;




int getpathbfs(int** edges, int n, int sv, int ev, bool* visited){
    
   queue<int>q;
    q.push(sv);
    int br=0;
    visited[sv]=true;
    while(!q.empty()){
        int current_vertex=q.front();
        q.pop();
    for(int i=0; i<n; i++){
        if(i==current_vertex)
            continue;
        if(edges[current_vertex][i]==1 && !visited[i]){
            visited[i]=true;
            q.push(i);
            
           // cout<<i<<" "<<current_vertex;
                data.insert(pair<int, int>(i, current_vertex));
            
            if(i==ev){
                br=1;
                break;
            }
        }
     }
        if(br==1)
            break;
   }
    
    map<int,int> :: iterator it;
    it = data.find(ev);
    if(it == data.end()){
        return 0;
    }
    else{
       ans.push_back(it->first);
       // cout<<it->first;
        int an=ev;
        while(an!=sv){
        an = it->second;
            ans.push_back(an);
         //   cout<<an;
            it = data.find(an);
        }
        
    }
    return 1;
}

int main(){
    int n, e;
    cin>>n>>e;
    int**edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0; i<e; i++){
            int f, s;
            cin>>f>>s;
            edges[f][s]=1;
            edges[s][f]=1;
    }
    int sv, ev;
    cin>>sv>>ev;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    vector<int> :: iterator it;
    if(getpathbfs(edges, n, sv, ev, visited)){
        for(it=ans.begin(); it!=ans.end(); it++){
            cout<<*it<<" ";
        }
    }
    
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    
    return 0;
}
/*vector<int>ans;
 unordered_map<int,int>getpath(int **edge, int n, int v1, int v2, bool *visited)
{
    unordered_map<int,int>m;
    queue<int>q;
    q.push(v1);
    visited[v1] = true;
    while(!q.empty())
    {
        int current_element = q.front();
        q.pop();
        if(current_element == v2)
            break;
        for(int i = 0; i < n; i++)
        {
            if(edge[current_element][i] == 1 && visited[i] == false)
            {
                q.push(i);
                m[current_element] = i;
                visited[i] = true;
            }
            if(i == v2)
                break;
          }
    }
    return m;
    
}
void find_path(int **edge, int n, int v1, int v2, bool *visited)
{
    unordered_map<int,int>m = getpath(edge,n,v1,v2,visited);
    unordered_map<int,int>::iterator it;
    for(it = 0; it < m.size(); it++)
    {
        
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    int **edge = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for(int j = 0; j < n; j++)
            edge[i][j] = 0;
    }
    for(int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        edge[start][end] = 1;
        edge[end][start] = 1;
    }
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    int v1, v2;
    cin >> v1 >> v2;
    
    find_path(edge,n,v1,v2,visted);
}*/
