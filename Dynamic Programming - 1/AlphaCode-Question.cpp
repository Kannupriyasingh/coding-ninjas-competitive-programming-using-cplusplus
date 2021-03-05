/*
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1
*/


#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

/*int solve(int *num, int size){
    
    if(size == 0 || size == 1)
        return 1;
    int ans = solve(num, size - 1);
    if(num[size - 2]*10 + num[size - 1] <= 26)
    {
        ans += solve(num, size - 2);
    }
    return ans;
}*/

/*int solve(int *num, int size)
{
    int *ans = new int[size + 1];
    ans[0] = 1;
    ans[1] = 1;
    if(int i = 2; i <= size; i++)
    {
        ans[i] = solve(num,size-1);
        if(num[i-2]*10+num[i-1] <= 26)
            ans[i] += solve(num,size-2);
    }
    int output = ans[size];
    delete [] ans;
    return output;
}

int main()
{  // int *arr = new int[5000];
    //int n = arr.size();
  
    int n;
    int size = n.size();
   cout << solve(n,size) << endl;
    return 0;
}*/
/*
int solve(char *a, int n)
{
    int count[n + 1] = {0};
    count[0] = 1;
    count[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        count[i] = 0;
        
        if(a[i - 1] > '0')
            count[i] = count[i - 1];
        if(a[i - 2] == '1' || (a[i - 2] == '2' && a[i - 1] < '7'))
            count[i] += count[i - 2];
    }
    int ans = count[n];
    //delete [] count;
    return ans;
}
int main()
{
    //char *a = new char[5]; 
    char a[20];
    cin >> a;
    int n = strlen(a);
    cout << solve(a,n);
}
*/

//My Code

int numCodes(int* input, int size)
{
    int* output = new int[size + 1]();

    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i <= size; i++)
    {
        if(input[i-1]!=0)
        	output[i]+= output[i - 1]%mod;
        if(input[i-2] * 10 + input[i-1] <= 26 && input[i-2] != 0)
        {
            output[i] += output[i-2] % mod;
        }
        output[i] %=mod;
    }
    return output[size];
}


int main()
{
    int size = 5000+1;
    int *input = new int[size];
    while(true){
        string s;
        cin>>s;
        if(s == "0")
        {
            break;
        }
            
        for(int i = 0; i < s.size(); i++)
        {
            input[i] = s[i] - '0';
        }
        
        cout << numCodes(input, s.size())<<endl;
    }
    
    return 0;
}
