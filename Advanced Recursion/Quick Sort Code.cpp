/*
Sort an array A using Quick Sort.
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
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int input[], int start, int end)
{
    int pivot = input[end];
    int i = start - 1;
    for(int j = start; j <= end - 1; j++)
    {
        if(input[j] < pivot)
        {
            i++;
            swap(&input[i],&input[j]);
        }
    }
    swap(&input[i + 1], &input[end]);
    return (i + 1);
}
void quick_sort(int input[], int start, int end)
{
    if(start >= end)
        return;
    
    int pi = partition(input, start, end);
    quick_sort(input, start, pi - 1);
    quick_sort(input, pi + 1, end);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
     
  */
    quick_sort(input, 0, size - 1);

}

#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


