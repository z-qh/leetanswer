#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>


using namespace std;

//斐波那契数列
int fib(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int FN = 1;
  int FN_1 = 1;
  int FN_2 = 0;
  for (int i = 0; i < n - 1; i++)
  {
    FN = FN_1 + FN_2;
    FN = FN % 1000000007;
    FN_2 = FN_1;
    FN_1 = FN;
  }
  return FN;
}
//斐波那契数列
void test10I()
{
  cout << "斐波那契数列" << endl;
  cout << fib(10) << endl;
}

//青蛙跳台阶问题
int numWays(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int N = 1;
  int N_1 = 1;
  int N_2 = 0;
  for (int i = 0; i < n; i++)
  {
    N = N_1 + N_2;
    N = N % 1000000007;
    N_2 = N_1;
    N_1 = N;
  }
  return N;
}
//青蛙跳台阶问题
void test10II()
{
  cout << "青蛙跳台阶问题" << endl;
  cout << numWays(10) << endl;
}