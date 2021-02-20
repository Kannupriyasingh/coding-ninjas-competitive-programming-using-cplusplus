/*
In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
Note: We don't have to mention names whose frequency is 1.
Input Format:
The only line of input will have a string ‘str’ with space separated first names of students.
Output Format:
Print the names of students along with their count if they are repeating. If no name is repeating, print -1
Constraints:
1 <= |str| <= 10^5
Time Limit: 1 second
Sample Input 1:
Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
Sample Output 1:
harshit 2
Ayush 3
Iti 2
Sample Input 2:
Abhishek Harshit Ayush Iti
Sample Output:
-1
*/



#include <iostream>
/*#include <bits/stdc++.h>
using namespace std;
int solve(string s)
{   map<string,int>m;
    int it = 0, i  = 0;
 	string word="";
    while(s[i] != '\0')
    {
        if (s[i] == ' ') { 
            if (m.find(word) == m.end()) { 
                m.insert(make_pair(word, 1)); 
                word = ""; 
            }  
            else { 
                cout<<word<<endl;
                m[word]++; 
                word = ""; 
            } 
        } 
  
        else
            word += s[i];
    	i++;
    }
 	if (m.find(word) == m.end()) 
        m.insert(make_pair(word, 1));  
    else
        m[word]++; 
 	int flag=0;
	for(auto i : m)
 	{
    	if(i.second > 1)
        {
            cout<<i.first<<" "<<i.second<<endl;
 			flag=1;
        }
    }
 	return flag;
}
int main()
{
    string s;
    //cin.getline(s);
    getline(cin,s);
    if(!solve(s))
        cout<<-1;
}





*/





#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(string s)
{ 
    int n = s.size();
    map<string,int>m;
    string word = "";
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == ' ')
        {
            if(m[word] == '\0' || m[word] != '\0')
            {
                m[word]++;
                word = "";
            }
                
        }
        else
            word = word + s[i];
            
      i++;
    }
    if(m[word] == '\0' || m[word] != '\0')
        m[word]++;
 
    bool flag = 0;
    for(auto i : m)
    {
        if(i.second > 1)
        {
            cout << i.first <<" "<< i.second <<endl;
            flag = 1;
        }
    }
    return flag;
 
}
int main()
{
    string s;
    //cin.getline(s);
    getline(cin,s);
    if(!solve(s))
        cout << -1;
    
    
}













