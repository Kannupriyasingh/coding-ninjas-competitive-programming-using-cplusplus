/*
input: 2 10 5
output: 4

input: 2 5 5
output: 2
*/
#include <iostream>
using namespace std;
// to find a to the power b modulo c ( a^b % c)
int solve(int a, int b, int c)
{
    if(a == 0)
    return 0;
    
    if(b == 1)
    return a;
    
    long ans;
    if(b % 2 == 0)
    {
        long small_ans = solve(a, b/2, c);
        ans = ((small_ans*small_ans) % c);
    }
    if(b % 2 != 0)
    {
        long small_ans = solve(a, b/2, c);
        ans = (((small_ans*small_ans) % c)*(a % c) % c);
    }
    //return int(ans);
    //to handle the negative intergers also we need to return like this
    return int((ans+c)%c);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);

    return 0;
}
