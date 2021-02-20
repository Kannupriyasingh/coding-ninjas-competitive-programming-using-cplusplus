/*
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
Input Format:
First line will have an integer ‘n’ denoting the number of shops in market.
Next line will have ‘n’ numbers denoting the price of one momo of each shop.
Next line will have an integer ‘q’ denoting the number of days she will visit the market.
Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= X <= 10^9
Output:
There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
Explanation:
Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.
*/


#include<bits/stdc++.h>
using namespace std;
void solve(int a1[], int n, int money)
{   int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(money < a1[i])
        {cout<<i<<" "<<money - a1[i - 1];
         return;
        }
        
            
    }
}
    
    
    
int main()
{   int sum = 0;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    int b[q];
    for(int i = 0; i < q; i++)
        cin >>b[i];
    int a1[n];
    for(int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        a1[i] = sum;
    }
    for(int i = 0; i < q; i++)
    {
        solve(a1, n, b[i]);
        cout<<endl;
    }
}


































/*int initial_shop = 0;
void solve(int a[], int n, int money, int initial_shop)
{   int m = money;
    int momos = 0;
    int index = -1;
    for(int i = 0; i < n; i++)
    {
        if(m >= a[i])
        {
            m = m - a[i];
            momos++;
        }
        else
        {
            index = i;
        }
    }
 initial_shop = index;
cout << momos <<" "<< m;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    int b[q];
    for(int i = 0; i < q; i++)
    cin >> b[i];
    
    for(int i = 0; i < q; i++)
    {  int money = b[i];
        solve(a, n, money, initial_shop);
        cout << endl;
    }
	return 0;
}*/
