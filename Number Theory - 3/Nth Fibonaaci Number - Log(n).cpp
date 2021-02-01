/*
input: 8
output: 21

explanation:
0  1  2  3  4  5  6  7  8
0  1  1  2  3  5  8  13  21
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void multiply(int A[2][2], int M[2][2]){
    //z -> zeroth, f -> first
    int zrowzcol = A[0][0]*M[0][0] + A[0][1]*M[1][0];
    int zrowfcol = A[0][0]*M[0][1] + A[0][1]*M[1][1];
    int frowzcol = A[1][0]*M[0][0] + A[1][1]*M[1][0];
    int frowfcol = A[1][0]*M[0][1] + A[1][1]*M[1][1];
    
    A[0][0] = zrowzcol;
    A[0][1] = zrowfcol;
    A[1][0] = frowzcol;
    A[1][1] = frowfcol;
}
void power(int A[2][2], int n){
    
    //base case
    if(n == 0|| n == 1)
    return;
    
    power(A,n/2);
    
    //multiply A^n/2 and A^n/2
    multiply(A,A);
    
    //if n is odd then we have to multiply the original "A" array again
    if((n%2) != 0)
    {
        int M[2][2] = {{1,1},{1,0}};
        multiply(A,M);
    }
    
}
int solve(int n){
    
    int A[2][2] = {{1,1},{1,0}};
    if(n == 0)
    return 0;
    
    power(A,n-1);
    return A[0][0];
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}
