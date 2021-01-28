#include <iostream>
using namespace std;
// to find a to the power b modulo c ( a^b % c)
int solve(int a, int b, int c)
{
   if(a == 0)
   return 0;
   
   int to_mul = 1;
   int ans = 1;
   int power_of_a_became = 1;
   while(b >= 1)
   {
       int mod_with_two = b % 2;
       if(mod_with_two == 1){
           power_of_a_became = (power_of_a_became * to_mul) % c;
           ans = (ans * a)%c;
       }
       to_mul *= 2;
       a = (a*a)%c;
   }
   return ans;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);

    return 0;
}
