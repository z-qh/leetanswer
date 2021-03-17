#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
  return a > b ? a : b;
}

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
//����0-1��������
void test01()
{
  vector<int> W = { 2,1,3,2 };
  vector<int> V = { 3,2,4,2 };
  int ans = bag01(4, 5, W, V);
  cout << "����0-1�������⣺" << endl;
  cout << ans << endl;
}

//�ظ�������
int findRepeatNumber(vector<int>& nums)
{
  int len = nums.size();
  sort(nums.begin(), nums.end());
  for (int i = 0; i < len; i++)
  {
    if (nums[i] == nums[i + 1])
      return nums[i];
  }
  return nums[len - 1];
}
//�����ظ�������
void test02()
{
  vector<int> A = { 2,2,1,3,6,7,88,14 };
  int ans = findRepeatNumber(A);
  cout << "�����ظ������֣�" << endl;;
  cout << ans << endl;
}

//��ά�����еĲ���
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
  int rows = matrix.size();
  if (rows == 0)
    return false;
  int cols = matrix[0].size();
  if (cols == 0)
    return false;
  for (int i = 0; i < rows; i++)
  {
    if (matrix[i][0] <= target && matrix[i][cols - 1] >= target)
    {
      for (int j = 0; j < cols; j++)
      {
        if (matrix[i][j] == target)
          return true;
      }
    }
    else
      continue;
  }
  return false;
}

//���Զ�ά�����еĲ���
void test03()
{
  vector<vector<int>> A = 
  { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
  bool ans = findNumberIn2DArray(A, 5);
  cout << "���Զ�ά�����еĲ���" << endl;
  cout << ans << endl;
}

//��β��ͷ��ӡ����
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) :val(x), next(nullptr) {}
};
vector<int> reversePrint(ListNode* head)
{
  vector<int> result;
  while (head != nullptr)
  {
    result.insert(result.begin(), head->val);
    head = head->next;
  }
  return result;
}
//���Դ�β��ͷ��ӡ����
void test04()
{
  ListNode A(1), B(3), C(2);
  A.next = &B;
  B.next = &C;
  vector<int> ans = reversePrint(&A);
  cout << "���Դ�β��ͷ��ӡ����" << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
}

//쳲���������
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
//����쳲���������
void test05()
{
  cout << "����쳲���������" << endl;
  cout << fib(10) << endl;
}

//������̨������
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
//����������̨������
void test06()
{
  cout << "����������̨������" << endl;
  cout << numWays(10) << endl;
}
//��ת�������С����
int minArray(vector<int>& numbers)
{
  if (numbers.size() == 0)
    return 0;
  int now = numbers[0];
  int last = now;
  for (int i = 0; i < numbers.size(); i++)
  {
    now = numbers[i];
    if (last > now)
      return now;
    last = now;
  }
  return numbers[0];
}
//������ת�������С����
void test07()
{
  vector<int> A = { 3, 4, 5, 1, 2 };
  int ans = minArray(A);
  cout << "������ת�������С����" << endl;
  cout << ans << endl;
}
//�����е�·��
bool dfs(int i, int j, int** visited, vector<vector<char>>& board, string word, int n)
{
  if (n >= word.length())
    return true;
  if ((i - 1 >= 0) && (visited[i - 1][j] == 0) && (board[i - 1][j] == word[n]))
  {
    visited[i - 1][j] = 1;
    if (dfs(i - 1, j, visited, board, word, n + 1))
      return true;
    else
      visited[i - 1][j] = 0;
  }
  if ((i + 1 <= board.size() - 1) && (visited[i + 1][j] == 0) && (board[i + 1][j] == word[n]))
  {
    visited[i + 1][j] = 1;
    if (dfs(i + 1, j, visited, board, word, n + 1))
      return true;
    else
      visited[i + 1][j] = 0;
  }
  if (((j - 1 >= 0) && (visited[i][j - 1] == 0)) && (board[i][j - 1] == word[n]))
  {
    visited[i][j - 1] = 1;
    if (dfs(i, j - 1, visited, board, word, n + 1))
      return true;
    else
      visited[i][j - 1] = 0;
  }
  if (j + 1 <= board[0].size() - 1 && visited[i][j + 1] == 0 && board[i][j + 1] == word[n])
  {
    visited[i][j + 1] = 1;
    if (dfs(i, j + 1, visited, board, word, n + 1))
      return true;
    else
      visited[i][j + 1] = 0;
  }
  return false;
}
bool exist(vector<vector<char>>& board, string word) {
  int rows = board.size();
  if (rows == 0)
    return false;
  int cols = board[0].size();
  if (cols == 0)
    return false;
  int len = word.length();
  if (len > cols * rows)
    return false;
  if (len == 0)
    return true;
  int** used_array = new int* [rows];
  for (int i = 0; i < rows; i++)
    used_array[i] = new int[cols];
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      used_array[i][j] = 0;
  for (int m = 0; m < rows; m++)
    for (int n = 0; n < cols; n++)
      if (board[m][n] == word[0])
      {
        used_array[m][n] = 1;
        if (dfs(m, n, used_array, board, word, 1))
        {
          for (int i = 0; i < rows; i++)
            delete[] used_array[i];
          return true;
        }
        used_array[m][n] = 0;
      }
  for (int i = 0; i < rows; i++)
    delete[] used_array[i];
  return false;
}
//���Ծ����е�·��
void test08()
{
  vector<vector<char>> board = 
  { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
  bool ans =  exist(board, "ABCCED");
  cout << "���Ծ����е�·��" << endl;
  cout << ans << endl;
}
//������
int cuttingRope(int n)
{
  if (n == 2)
    return 1;
  if (n == 3)
    return 2;
  int m = n / 3;
  if (n % 3 == 1)
    return pow(3, m - 1) * 4;
  else if (n % 3 == 2)
    return pow(3, m) * 2;
  else
    return pow(3, m);
}
//���Լ�����
void test09()
{
  cout << "���Լ�����" << endl;
  cout << cuttingRope(22) << endl;
}

//������II
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
//���Լ�����II
void test10()
{
  cout << "���Լ�����II" << endl;
  cout << cuttingRope2(555) << endl;
}
//��������1�ĸ���
int hammingWeight(uint32_t n)
{
  int bit_count = 0;
  while (n / 2 != 0 || n % 2 != 0)
  {
    if (n % 2)
      bit_count++;
    n /= 2;
  }
  return bit_count;
}

//���Զ�������1�ĸ���
void test11()
{
  cout << "���Զ�������1�ĸ���" << endl;
  cout << hammingWeight(8191) << endl;
}

int main()
{
  test01();
  test02();
  test03();
  test04();
  test05();
  test06();
  test07();
  test08();
  test09();
  test10();
  test11();
  return 0;
}