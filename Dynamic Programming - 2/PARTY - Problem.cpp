/*
You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input
The first line of the input specifies your party budget and the number n of parties.

The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number indicates the amount of fun of each party, given as an integer number ranging from 0 to 10.

The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space.

There are many test cases. Input ends with 0 0.
Output
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0
Sample Output
49 26
48 32
*/

#include <bits/stdc++.h>
using namespace std;
/*int helper(int* cost, int* fun, int n, int budget, int **dp)
{
    if(budget == 0 || n == 0)
        return 0;
    if(dp[n][budget] != -1)
        return dp[n][budget];
    if(cost[0] <= budget)
        dp[n][budget] = max(fun[0] + helper(cost+1,fun+1,n-1,budget-cost[0],dp), helper(cost+1,fun+1,n-1,budget,dp));
    else
        dp[n][budget] =  helper(cost+1,fun+1,n-1,budget,dp);
    return dp[n][budget];
}

int party(int* cost, int* fun, int n, int budget){

 int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[budget+1];
        for(int j = 0; j <= budget; j++)
            dp[i][j] = -1;
    }
 int ans = helper(cost,fun,n,budget,dp);
     for(int i = 0; i <= n; i++)
         delete [] dp[i];
    delete [] dp;
  //  cout<<budget;
return ans;        

}*/
#include<bits/stdc++.h>
using namespace std;

pair<int, int> minBudgetParty(int* budgets, int* fun, int maxBudget, int n, pair<int, int>**output)
{
	if(n == 0)
	{
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
    
	if(output[maxBudget][n].first != -1 && output[maxBudget][n].second != -1)
	{
		return output[maxBudget][n];
	}
    
	pair<int, int> ans;
	if(budgets[0] <= maxBudget)
	{
		pair<int, int>option1 = minBudgetParty(budgets + 1, fun + 1, maxBudget - budgets[0], n - 1, output);
		option1.first += budgets[0];
		option1.second += fun[0];
		pair<int, int>option2 = minBudgetParty(budgets + 1, fun + 1, maxBudget, n - 1, output);
		if(option1.second > option2.second)
		{
			ans= option1;
		}
		else if(option2.second > option1.second)
		{
			ans  = option2;
		}
		else
		{
			if(option1.first < option2.first)
			{
				ans = option1;
			}
			else
			{
				ans = option2;
			}
		}
	}
	else
	{
		ans = minBudgetParty(budgets + 1, fun + 1, maxBudget, n - 1, output);
	}
	output[maxBudget][n] = ans;
	return ans;
}
int main()
{
	while (true)
	{
		int maxBudget, n;              
		cin >> maxBudget >> n;
        
		if (maxBudget == 0 && n == 0)
		{
			break;
		}
        
        //taking array input
		int* budgets = new int[n];
		int* fun = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> budgets[i] >> fun[i];
		}


		//creating an output array
		pair<int, int>** output = new pair<int, int>*[maxBudget + 1];
		for (int i = 0; i <=maxBudget; i++)
		{
			output[i] = new pair<int, int>[n + 1];
			for (int j = 0; j <= n; j++)
			{
				output[i][j].first = -1;
				output[i][j].second = -1;
			}
		}

		pair<int, int> p;
		p = minBudgetParty(budgets, fun, maxBudget, n, output);
		cout << p.first << ' ' << p.second << endl;


		for (int i = 0; i < n + 1; i++)
		{
			delete [] output[i];
		}
		delete [] output;
	}
}

/*
int main()
{
    int maxBudget, n;
    while(true)
    {
        cin >> maxBudget >> n;
        if(budget == 0 && n == 0)
        {
            break;
        }
        
        int *budgets = new int[n];
        int* fun = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> budgets[i] >> fun[i];
        }
        
        //taking output array of dimensions n+1 and maxBudget+1
        int** output = new int*[n+1];
        for(int i = 0; i <= n; i++)
        {
            output[i] = new int[maxBudgets+1];
            for(int j = 0; j <= maxBudget; j++)
            {
                output[i][j] = -1;
            }
        }
        
        int result = minBudgetParty(budgets, fun, n, maxBudget, output);
        
    }
}*/


/*
int main(){
    int budget;
  cin >> budget;
     int n; 
  cin >> n;
    int i = 0;
     int* cost = new int[n];
  int* fun = new int[n];
    while (n != 0 && budget != 0)
    {
        while(i != n-1)
        {  int a,b;
            cin >> a >> b;
            cost[i] = a;
            fun[i] = b;
            i++;
        }
        cout << party(cost, fun, n, budget);
           int budget;
         cin >> budget;
          int n; 
          cin >> n;
    }
 return 0;


 }*/

