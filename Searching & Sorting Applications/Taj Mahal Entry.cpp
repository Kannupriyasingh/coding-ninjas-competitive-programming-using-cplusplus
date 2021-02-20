/*
Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal. He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. There are total ‘n’ windows which provide the tickets to get entry into Taj Mahal. There are ‘Ai’ people already present at each window to get the tickets. Each window gives ticket to one person in one minute. Initially, Aahad stands in front of the first window. After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket. If he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to 1st again and so on. Find the window number at which he will get the ticket.
Input Format:
First line contains a single integer ‘n’ denoting the no. of windows.
Next line contains ‘n’ space separated integers denoting the no. of people already standing in front of the ith window. (1 <= i <= n)
Output Format:
Print a single integer denoting the window number that Aahad will get ticket from.
Constraints:
1 <= n <= 10^5
1 <= Ai <= 10^9
Sample Input:
4
2 3 2 0
Sample Output:
3
Explanation:
Aahad at Window 1: [2, 3, 2, 0]
Aahad at Window 2: [1, 2, 1, 0]
Aahad at Window 3: [0, 1, 0, 0]
So, when Aahad is at window 3, he got zero people before him. Hence, he will get the ticket at window 3.
*/

#include<bits/stdc++.h>
using namespace std;
//index+time*n >= a[i]
#include<bits/stdc++.h>
using namespace std;

int getWindow(int *a,int n)
{
    vector<int> v;

    for(int i=0;i<n;i++)
    {
        int s=0;
        int e=1000000000;
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(i+n*mid>=a[i])
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }

        v.push_back(ans);
    }
    int min=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]<v[min])
        {
            min=i;
        }
    }


//    for(int i=0;i<n;i++)
//    {
//        cout<<v[i]<<" ";
//    }
    return min+1;
}



int main()
{
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<getWindow(a,n);
	return 0;
}














/*#include<bits/stdc++.h>
using namespace std;

int getWindow(int *a,int n)
{
    vector<int> v;

    for(int i=0;i<n;i++)
    {
        int s=0;
        int e=1000000000;
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(i+n*mid>=a[i])
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }

        v.push_back(ans);
    }
    int min=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]<v[min])
        {
            min=i;
        }
    }


//    for(int i=0;i<n;i++)
//    {
//        cout<<v[i]<<" ";
//    }
    return min+1;
}



int main()
{
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<getWindow(a,n);
	return 0;
}

*/

/*int check(int a[], int n, int mid)
{
    for(int i = 1; i <= n; i++)
    {
        if(i + mid * n >= a[i])
            return i;
    }
    return -1;
}
int solve(int a[],int n)
{    int ans = INT_MAX;
    int low = 0;
    long long int high = 1000000000;
     if(low > high)
        return 0;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int ans1 = check(a,n,mid);
        if(ans1 > 0)
        {
            ans = min(ans, ans1);
            high = mid;
        }
        else
            low = mid + 1;
    }
 return ans;
}


int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout<<solve(a,n);
	return 0;
}
*/
