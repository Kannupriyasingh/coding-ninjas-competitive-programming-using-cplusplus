/*
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl "\n";
#define f(i,n) for(i=0;i<n;i++)

ll merge(ll a[],ll start,ll mid,ll end,ll n)
{
    ll i=start,j=mid,k=0,sum=0,temp[n];
    while(i<mid && j<=end)
    {
        if(a[i]<a[j])
        {
            sum=sum+a[i]*(end-j+1);
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=end)
    {
        temp[k++]=a[j++];
    }
    k=0;
    for(i=start;i<=end;i++)
    {
        a[i]=temp[k];
        k++;
    }
    return sum;
}

ll merge_sort(ll arr[],ll start,ll end,ll n)
{
    ll sum=0;
    if(start>=end)
        return sum;
    else
    {
        ll mid=start+(end-start)/2;
        ll sum_left=merge_sort(arr,start,mid,n);
        ll sum_right=merge_sort(arr,mid+1,end,n);
        ll mysum=merge(arr,start,mid+1,end,n);
        return sum_left+sum_right+mysum;
    }
    
}
int main()
{
	ll t;
	cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        ll arr[n];
        f(i,n)
        {
            cin>>arr[i];
        }
        ll sum=merge_sort(arr,0,n-1,n);
        cout<<sum<<endl;
    }
    return 0;
}









































/*#include<bits/stdc++.h>
using namespace std;

int merge(int a[], int low, int mid, int high)
{  
 int ans[high - low + 1];
    int i = low, j = mid, k = 0;
    while(i < mid && j <= high)
    {
        if(a[i] < a[j])
        {  int sum = 0;
            sum += high-j+1;
            int mul = a[i]*sum;
            ans[k] = mul;
            k++;
            i++;
        }
        else if(a[i] >= a[j])
        j++;
        
    }
 while(i < mid)
  ans[k++] = a[i++];
 
 while(j <= high)
  ans[k++] = a[j++];
     
 for(int i = low, k = 0; i <= high; i++, k++)
     a[i] = ans[k];
     int sum1 = 0;
 for(int i = 0; i < high; i++)
     sum1 += a[i];
 return sum1;
*/












/*int solve(int a[],int low, int high)
{  int sum = 0;
    if(low >= high)
        return sum;
    int mid = (low + high)/2;
    int first = solve(a,low,mid);
    int second = solve(a,mid + 1,high);
    int third = merge(a,low,mid + 1,high);
 
 return first + second + third;
}
int main() {

	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        cout<<solve(a,0,n-1);
    }
}
*/





























/*
//complexity of this code is O(n^2)
#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            if(a[j] < a[i])
                sum += a[j];
        }
    }
    return sum;
}
int main() {
 
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        cout << solve(a,n) << endl;
    }

}*/
