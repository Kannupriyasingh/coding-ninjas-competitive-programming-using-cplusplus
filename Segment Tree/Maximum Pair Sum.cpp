/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/

/*#include<bits/stdc++.h>
using namespace std;

void build_tree(int arr[], int *tree, int root, int start, int end)
{
    int mid = (start + end) / 2;
    if(start == end)
    {
        tree[root] = arr[start];
        return;
    }
    build_tree(arr,tree,2*root,start,mid);
    build_tree(arr,tree,2*root + 1, mid + 1, end);
    tree[root] = tree[2*root] + tree[2*root + 1];

}

void update(int arr[], int *tree, int root, int start, int end, int x, int y)
{
    int mid = (start + end)/2;
    if(start == end)
    {
        arr[x] = y;
        tree[root] = y;
        return;
    }
    update(arr,tree,2*root,start,mid,x,y);
    update(arr,tree,2*root+1,mid+1,end,x,y);
    tree[root] = tree[2*root] + tree[2*root + 1];
    
}
int query(int arr[], int *tree, int root, int start, int end, int l, int r)
{
    int mid = (start + end)/2;
    if(start == end)
        return tree[root];
    int option1 = query(arr, tree, 2*root, start, mid, l, r);
    int option2 = query(arr, tree, 2*root+1, mid+1, end, l, r);
    int ans = option1 + option2;
    return ans;
}
int main() {

	int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int q;
    cin >> q;
    int *tree = new int[2*n];
    while(q--)
    {
        char option;
        int l, r;
        cin >> option >> l >> r;
        if(option == 'U')
            update(arr,tree,1,0,n-1,l-1,r);
        else
            cout << query(arr,tree,1,0,n-1,l-1,r-1) << endl;
    }
    return 0;
}*/
#include<iostream>
#include<utility>
#include<algorithm>
#include<climits>
using namespace std;

pair<int,int> query(pair<int,int>* tree, int start, int end, int treeNode, int left, int right){
	
	//Completely out
	if (left>end || right<start)
	{
		pair<int,int> temp = make_pair(INT_MIN, INT_MIN);
		return temp;
	}

	//Completely inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//Partially inside
	int mid = (start+end)/2;

	pair<int,int> l = query(tree, start, mid, 2*treeNode+1, left, right);
	pair<int,int> r = query(tree, mid+1, end, 2*treeNode+2, left, right);


	pair<int,int> result;
	result.first = max(l.first,r.first);
    result.second = min(max(l.first,r.second),max(l.second,r.first));
   	return result;

}


void update(int* arr, pair<int,int>* tree, int start, int end, int treeNode, int idx, int value){
	int mid = (start+end)/2;

	if (start == end)
	{
		arr[idx] = value;
		tree[treeNode] = make_pair(value, INT_MIN);
		return;
	}

	if (idx<=mid)
	{
		update(arr, tree, start, mid, 2*treeNode+1, idx, value);
	}else{

		update(arr, tree, mid+1, end, 2*treeNode+2, idx, value);
	}

	pair<int,int> left = tree[2*treeNode+1];
	pair<int,int> right = tree[2*treeNode+2];

	tree[treeNode].first = max(left.first,right.first);
	tree[treeNode].second = min(max(left.first,right.second),max(left.second,right.first));
	return;
}


void create(int* arr, pair<int,int>* tree, int start, int end, int treeNode){
	if (end == start)
	{
		tree[treeNode] = make_pair(arr[start], INT_MIN);
		return;
	}

	int mid = (start+end)/2;

	create(arr, tree, start, mid, 2*treeNode+1);
	create(arr, tree, mid+1, end, 2*treeNode+2);

	pair<int, int> left = tree[2*treeNode+1];
	pair<int, int> right = tree[2*treeNode+2];

	tree[treeNode].first = max(left.first,right.first);
	tree[treeNode].second = min(max(left.first,right.second),max(left.second,right.first));
	//ye isliye kiya jisse tree[treenode].first ka data tree[treenode].second mei nahi aa jaye
	//hume max and second max daalne hien .first and .second mei. 
	return;

	
}

int main()
{
	int n, q;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cin>>q;
	pair<int,int>* tree = new pair<int,int>[4*n];
	create(arr, tree, 0, n-1, 0);
	while(q--){
		char a;
		int b, c;
		cin>>a>>b>>c;

		if (a == 'Q')
		{
			pair<int,int> result = query(tree, 0, n-1, 0, b-1, c-1);
			cout << result.first+result.second << endl;
		}else{
			update(arr, tree, 0, n-1, 0, b-1, c);
		}

	}


	return 0 ; 



}
