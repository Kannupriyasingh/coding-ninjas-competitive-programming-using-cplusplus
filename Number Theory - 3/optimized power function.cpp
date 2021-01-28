/*
input: 2 3
output: 8

input: 5 3
output: 125
*/
#include <iostream>
using namespace std;

int power(int x, int n, int &val)
{
  if(n == 1)
  return x;
  
  if(n % 2 == 0)
  {
    val = power(x, n/2, val);
    val = val*val;
    return val;
  }
  if(n % 2 != 0)
  {
    val = power(x, n/2, val);
    val = val*val*x;
    return val;
  }
  
}
int main()
{
  int x, n;
  cin >> x >> n;
  int val = 1;
  cout << power(x, n, val);
}
