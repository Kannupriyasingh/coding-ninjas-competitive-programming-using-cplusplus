/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include<bits/stdc++.h>
int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
if(h == 0 || h == 1)
    return 1;

int m = pow(10,9) + 7;
int x = balancedBTs(h - 1);
int y = balancedBTs(h - 2);
//int ans = x*x + 2*x*y;
    //typecast in long
    long res1 = (long)x*x;
    long res2 = (long)x*y*2;
    
    int ans1 = (int)(res1 % m);
    int ans2 = (int)(res2 % m);
    
    int ans = (ans1 + ans2) % m;
 
    return ans;
}
#include <iostream>
using namespace std;

#include "solution.h"

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
