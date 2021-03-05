/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
void buildtree(int* arr, int* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildtree(arr, tree, start, mid, 2 * treenode);
	buildtree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree[treenode] = min(tree[2 * treenode] , tree[2 * treenode + 1]);
}
void updatetree(int* arr, int* tree, int start, int end, int treenode, int index, int value)
{
	if (start == end)
	{
		arr[index] = value;
		tree[treenode] = value;
		return;
	}
	int mid = (start + end) / 2;
	if (index > mid)//right
	{
		updatetree(arr, tree, mid + 1, end, 2 * treenode + 1, index, value);
	}
	else//left
	{
		updatetree(arr, tree, start, mid, 2 * treenode, index, value);
	}
	tree[treenode] = min(tree[2 * treenode] , tree[2 * treenode + 1]);
}
int query(int* tree, int start, int end, int treenode, int left, int right)
{
	if(start>right || end <left)
	{
		return INT_MAX;
        
	}
    
    if(start>=left && end<=right)
    {
        return tree[treenode];
    }
	int mid=(start+end)/2;
	int ans1=query(tree, start, mid, 2*treenode, left, right);
	int ans2=query(tree, mid+1, end, 2*treenode+1, left, right);
	return min(ans1, ans2);
}
int main()
{
	int n, q;
	cin>>n>>q;
	int *arr=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int *tree=new int [4*n];
	buildtree(arr, tree, 0, n - 1, 1);
	//at this point of time i have my tree with me.
	while(q--)
	{
		char query_type;
		cin>>query_type;
		if(query_type=='q')
		{
			int l, r;
			cin>>l>>r;
			cout<<query(tree, 0, n-1, 1, l-1, r-1)<<endl;
		}
		else
		{
			int x, y;
			cin>>x>>y;
			//we need to update arr[x]=y;
			updatetree(arr, tree, 0, n - 1, 1, x-1, y);
		}
	}
}









































/*#include<bits/stdc++.h>
using namespace std;

void build_tree(int arr[], int *tree, int root, int start, int end)
{
    int mid = (start + end)/2;
    if(start == end)
    {
        tree[root] = arr[start];
        return;
    }
    build_tree(arr,tree,2*root,start,mid);
    build_tree(arr,tree,2*root + 1,mid+1,end);
    tree[root] = min(tree[2*root],tree[2*root + 1]);
}
void update(int arr[], int *tree, int root, int start, int end, int x, int y)
{
    if(start == end)
    {
        arr[x] = y;
        tree[root] = y;
        return;
    }
    int mid = (start + end) / 2;
    if(x <= mid)
    update(arr,tree,2*root,start,mid,x,y);
    else
    update(arr,tree,2*root + 1,mid+1,end,x,y);
    tree[root] = min(tree[2*root], tree[2*root + 1]);
    
}
int query(int *tree, int start, int end, int root, int l, int r)
{
    if(start > l || end < r)
        return INT_MAX;
    
    if(start <= l && end >= r)
        return tree[root];
    
    int mid = (start + end) / 2;
    int option1 = query(tree,start,mid,2*root,l,r);
    int option2 = query(tree,mid+1,end,2*root+1,l,r);
    int ans = min(option1, option2);
    return ans;
        
}
int main() {

	int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int *tree = new int[2*n];
     build_tree(arr,tree,1,0,n-1);
    while(q--)
    {
        char option;
        int l, r;
        cin >> option >> l >> r;
      if(option == 'u')
          update(arr,tree,1,0,n-1,l-1,r);
        else
            query(tree,0,n-1,1,l-1,r-1);
            
    }
    delete [] tree;
    return 0;
    }
    
*/
