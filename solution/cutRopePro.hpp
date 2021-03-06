#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;
 
//剪绳子
int cuttingRope(int n)
{
  if (n == 2)
    return 1;
  if (n == 3)
    return 2;
  int m = n / 3;
  if (n % 3 == 1)
    return (int)pow(3, m - 1) * 4;
  else if (n % 3 == 2)
    return (int)pow(3, m) * 2;
  else
    return (int)pow(3, m);
}
//剪绳子
void test14I()
{
  cout << "剪绳子" << endl;
  cout << cuttingRope(22) << endl;
}
//剪绳子II
int opt_pow(int base, int exponent)
{
  if (exponent == 0)
    return 1;
  long int temp;
  temp = opt_pow(base, exponent / 2) % 1000000007;
  temp = (temp * temp) % 1000000007;
  if (exponent % 2 == 1)
    temp = (temp * base) % 1000000007;
  return temp;
}
int cuttingRope2(int n)
{
  if (n == 2)
    return 1;
  if (n == 3)
    return 2;
  int m = n / 3;
  if (n % 3 == 1)
    return ((long int)opt_pow(3, n - 1) * 4) % 1000000007;
  else if (n % 3 == 2)
    return ((long int)opt_pow(3, n) * 2) % 1000000007;
  else
    return opt_pow(3, m);
}
//剪绳子II
void test14II()
{
  cout << "剪绳子II" << endl;
  cout << cuttingRope2(555) << endl;
}