/*
Our college team is going to the sports fest to play a football match with our coach. There are n players in our team, numbered from 1 to n.
The coach will know the position of another team hence create a winning strategy. He creates the position of every player in a specific order so that we will win and then he starts swapping two players at a time to form the positions.
He swaps payers in such a way that it can't be understood by another team:
1. Any player can swap with the player directly at front him
2. One player can swap at most with two other players
If the specific order is formed then our team will win otherwise we will lose
Input Format
The First line contains numbers of players in team: n
The second line contains n space separated integers denoting the specific position of players: i-th integer denotes the position of Ai player in winning strategy
Output Format
If our team wins print "YES"(without quotes) and in next line print the minimum numbers of swapping required to form this specific order otherwise print "NO"(without quotes) 
Constraints
1 =< n <= 10^5 
1 <= Ai <= n
Sample Input1:
5
2 1 5 3 4
Sample Output1:
YES
3
Sample Input2:
5
2 5 1 3 4
Sample Output3:
NO   
Explaination
In the First Sample case, 
    Initial state: 1 2 3 4 5
    Three moves required to form this order:
    1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
In the second case, no way to form this specific order
*/


#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
	int swap = 0;
    bool flag = true;
    for(int i=n-1;i>=0;i--){
        if(a[i] == i+1)
            continue;
        else{
            if(a[i-1] == i+1){
                a[i-1] = a[i];
                a[i] = i+1;
                swap++;
            }
            else if(a[i-2] == i+1){
                a[i-2] = a[i-1];
                a[i-1] = a[i];
                a[i] = i+1;
                swap += 2;
            }
            else{
                flag = false;
                break;
            }
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        cout<<swap<<endl;
    }
    else
        cout<<"NO";
}





/*using namespace std;
 
 // some testcases are not working giving WA
int solve(int a[], int n)
{   //bool ans = true;
   for(int i = 0; i < n; i++)
   {
       int num = a[i];
       if(i == num - 1 || i == num - 2 || i == num - 3 || i == num + 1 || i == num)
           continue;
        else
        {
            //ans = false;
            return false;
        }
    }
 int count = 0;
 for(int i = 0; i < n; i++)
 { // to check whether swapping occur or not
     if(a[i] != i - 1)
         count++;
 }
    
 int answer = count/2;
 return answer - 1;
    
}
int main() {

	int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = solve(a,n);
    if(ans != 0)
    {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    else
        cout<<"NO";
}
*/





