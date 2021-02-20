/*
Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
Input:
First line contains an integer denoting length of the string.
Next line contains the string.
Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’
Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
Sample Input:
6
aabsas
Sample output:
3 2 0
*/

#include<bits/stdc++.h>
using namespace std;
void solve(string s,int n)
{
    int a1=0,s1=0,p1=0;
    map<char,int>m;
    for(int i = 0; i < n; i++)
        m[s[i]]++;
    map<char,int>::iterator it;
    for(it = m.begin(); it!=m.end(); it++)
    {
        if(it->first == 'a')
            a1 = it->second;
        else if(it->first == 's')
            s1 = it->second;
        else if(it->first == 'p')
            p1 = it->second;
    }
    cout<<a1<<" "<<s1<<" "<<p1;

}
int main()
{   int n;
    cin>>n;
    string s;
    cin >> s;
    solve(s,n);
	return 0;
}
