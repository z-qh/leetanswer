#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


//0-1�������⣬�ݹ�
int bag01(int n, int m, vector<int>w, vector<int> v)
{
  //n=0��û��ʣ����Ʒ
  if (n == 0)
    return 0;
  //ʣ��Ŀռ䲻��װ��n����Ʒ
  if (m < w[n - 1])
    return bag01(n-1, m, w, v);
  //�û��߲��õ�n����Ʒ
  int tempb = bag01(n - 1, m - w[n-1], w, v) + v[n-1];
  int tempa = bag01(n - 1, m, w, v);
  return tempa > tempb ? tempa : tempb;
}


int max(int a, int b)
{
  return a > b ? a : b;
}
//0-1�������⣬����
int bag02(int n, int m, vector<int>w, vector<int>v)
{
  int ans = 0;
  //������Ʊ�ռ�
  int **F = new int* [n+1];
  for (int k = 0; k < n+1; k++)
    F[k] = new int[m+1];
  //��ʼ�������б��һ��Ϊ��
  for (int k = 0; k < m+1; k++)
    F[0][k] = 0;
  //�ӵ�һ�п�ʼ������
  for (int i = 1; i <= n; i++)
  {
    for (int j = m; j >= 0; j--)
    {
      //�Ų��µ�i����Ʒ
      if (j < w[i - 1])
        F[i][j] = F[i - 1][j];
      else
        F[i][j] = max(F[i - 1][j], F[i - 1][j - w[i - 1]] + v[i - 1]);
    }
  }
  //���ص�ǰ��
  ans = F[n][m];
  //�ͷŶѿռ�
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