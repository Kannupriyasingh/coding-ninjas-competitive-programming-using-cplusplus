/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

void merge(int input[], int start, int mid, int end)
{  
    int ans[end-start+ 1];  //this
    int i = start, j = mid, k = 0;  // i will start from start not 0 & j from mid 
    while(i < mid && j <= end)
    {
        if(input[i] <= input[j])
            ans[k++] = input[i++];
        else
            ans[k++] = input[j++];
    }
    while(i < mid)
        ans[k++] = input[i++];
    while(j <= end)
        ans[k++] = input[j++];
    
    for(int i = start, k = 0; i <= end; i++, k++) //i from start
        input[i] = ans[k];
    
}

void merge_sort(int input[], int start, int end)
{
    if(start >= end)
        return;
    // while(start < end)
    // {
        int mid = (start + end)/2;
        merge_sort(input, start, mid);
        merge_sort(input, mid + 1, end);
        merge(input, start, mid + 1, end);
    // }
}

void mergeSort(int input[], int size){
	merge_sort(input,0,size-1);
        
}

























/*void merge(int input[], int start, int mid, int end)
{  
    int ans[end - start + 1];
    int i = start, j = mid, k = 0;
    while(i < mid && j <= end)
    {
        if(input[i] <= input[j])
            ans[k++] = input[i++];
        else
            ans[k++] = input[j++];
    }
    while(i < mid)
        ans[k++] = input[i++];
    while(j <= end)
        ans[k++] = input[j++];
    
    for(int i = 0, k = 0; i <= end; i++, k++)
        input[i] = ans[k];
    
}

void merge_sort(int input[], int start, int end)
{
    if(start >= end)
        return;
    //while(start < end)
    
        int mid = (start + end)/2;
        merge_sort(input, start, mid);
        merge_sort(input, mid + 1, end);
        merge(input, start, mid + 1, end);
    
}

void mergeSort(int input[], int size){
	merge_sort(input,0,size-1);
        
}*/

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
