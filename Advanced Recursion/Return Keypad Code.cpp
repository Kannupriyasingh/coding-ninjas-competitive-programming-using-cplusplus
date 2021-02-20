/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <string>
#include<bits/stdc++.h>
using namespace std;

/*int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    
}*/
map<int,string> keyMap;
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    keyMap[0]="";
    keyMap[2]="abc";
    keyMap[3]="def";
    keyMap[4]="ghi";
    keyMap[5]="jkl";
    keyMap[6]="mno";
    keyMap[7]="pqrs";
    keyMap[8]="tuv";
    keyMap[9]="wxyz";

    if(num==0)
    {
        output[0]="";
        return 1;
    }
    else
    {
        int quo=num/10;
        int rem=num%10;
        int smallOutput=keypad(quo,output);   
        for(int j=0;j<smallOutput;j++)
        {
            string temp=output[j];
            for(int i=0;i<keyMap[rem].size();i++)
            {
                output[i*smallOutput+j]=temp+keyMap[rem][i];
            }
        }
        return smallOutput*keyMap[rem].size();
    }
}

#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
