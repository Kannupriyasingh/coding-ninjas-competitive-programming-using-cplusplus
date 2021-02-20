/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const string hashTable[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

void keypadRecurse(vector<int>v,int curr,char output[],int N){
    if(curr == N){
        cout << output << endl;
        return;
    }
    for(int i=0;i<hashTable[v[curr]].length();i++){
        output[curr] = hashTable[v[curr]][i];
        keypadRecurse(v,curr+1,output,N);
        if(v[curr] == 0 || v[curr] == 1)
            return;
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    vector<int> v;
    int c = 0;
    while(num > 0){
        v.push_back(num%10);
        num /= 10;
        c++;
    }
    reverse(v.begin(),v.end());
    char output[c+1];
    output[c] = '\0';
    keypadRecurse(v,0,output,c);
}

#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
