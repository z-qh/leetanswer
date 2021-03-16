#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


//0-1背包问题，递归
int bag01(int n, int m, vector<int>w, vector<int> v)
{
  //n=0则没有剩余物品
  if (n == 0)
    return 0;
  //剩余的空间不够装第n个物品
  if (m < w[n - 1])
    return bag01(n-1, m, w, v);
  //拿或者不拿第n个物品
  int tempb = bag01(n - 1, m - w[n-1], w, v) + v[n-1];
  int tempa = bag01(n - 1, m, w, v);
  return tempa > tempb ? tempa : tempb;
}


int max(int a, int b)
{
  return a > b ? a : b;
}
//0-1背包问题，递推
int bag02(int n, int m, vector<int>w, vector<int>v)
{
  int ans = 0;
  //分配递推表空间
  int **F = new int* [n+1];
  for (int k = 0; k < n+1; k++)
    F[k] = new int[m+1];
  //初始化递推列表第一行为零
  for (int k = 0; k < m+1; k++)
    F[0][k] = 0;
  //从第一行开始往后推
  for (int i = 1; i <= n; i++)
  {
    for (int j = m; j >= 0; j--)
    {
      //放不下第i个物品
      if (j < w[i - 1])
        F[i][j] = F[i - 1][j];
      else
        F[i][j] = max(F[i - 1][j], F[i - 1][j - w[i - 1]] + v[i - 1]);
    }
  }
  //返回当前解
  ans = F[n][m];
  //释放堆空间
  for (int k = 0; k < m; k++)
    delete [] F[k];
  delete[] F;
  return ans;
}

void test03()
{
  vector<int> W = { 2,1,3,2 };
  vector<int> V = { 3,2,4,2 };

  int ans = bag01(4, 5, W, V);
  
  cout << ans << endl;
}

int main()
{
  //test1();
  test03();
  return 0;
}