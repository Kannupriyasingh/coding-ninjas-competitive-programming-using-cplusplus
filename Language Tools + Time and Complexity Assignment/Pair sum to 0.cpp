/*
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
*/


/*void pairSum(int *input, int n) 
{  // not working for array having zero in it
    //Write your code here	 
    unordered_map<int, int>m;
    int no_of_zeros;
  for(int i = 0; i < n; i++)
  {   
      if(m.find(-1*input[i]) == m.end())
          m[input[i]]++;
      
      else
      {
          {     while(m[-1*input[i]]--)
              if(input[i] < -1*input[i])
              {
                  cout<<input[i]<<" "<<(-1*input[i])<<endl;
              }
             else
             {
                 cout<<-1*input[i]<<" "<<input[i]<<endl;
             }
               
                   
          }
          
            m[input[i]]++;
      }
  }
}*/
#include<bits/stdc++.h> 	
void pairSum(int *input, int n)
{	 
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int key = -1*input[i];
        //cout<<m[key]<<endl;
           
        if(m.count(key)>0)
        {
            int k = m[key];
            while(k--)
            {
                cout<<min(input[i],key)<<" "<<max(input[i],key)<<endl;
            }
        }
        if(m.count(input[i])==0)
        {
            m[input[i]]=1;
        }
        else m[input[i]]++;
    }   	     
}

#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
