#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

using namespace std;

int max(int a, int b)
{
  return a > b ? a : b;
}

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
//0-1背包问题
void test01()
{
  vector<int> W = { 2,1,3,2 };
  vector<int> V = { 3,2,4,2 };
  int ans = bag01(4, 5, W, V);
  cout << "0-1背包问题：" << endl;
  cout << ans << endl;
}

//重复的数字
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
//重复的数字
void test02()
{
  vector<int> A = { 2,2,1,3,6,7,88,14 };
  int ans = findRepeatNumber(A);
  cout << "重复的数字：" << endl;;
  cout << ans << endl;
}

//二维数组中的查找
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

//二维数组中的查找
void test03()
{
  vector<vector<int>> A = 
  { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
  bool ans = findNumberIn2DArray(A, 5);
  cout << "二维数组中的查找" << endl;
  cout << ans << endl;
}

//从尾到头打印链表
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
//从尾到头打印链表
void test04()
{
  ListNode A(1), B(3), C(2);
  A.next = &B;
  B.next = &C;
  vector<int> ans = reversePrint(&A);
  cout << "从尾到头打印链表" << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
}

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
void test05()
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
void test06()
{
  cout << "青蛙跳台阶问题" << endl;
  cout << numWays(10) << endl;
}
//旋转数组的最小数字
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
//旋转数组的最小数字
void test07()
{
  vector<int> A = { 3, 4, 5, 1, 2 };
  int ans = minArray(A);
  cout << "旋转数组的最小数字" << endl;
  cout << ans << endl;
}
//矩阵中的路径
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
  delete[] used_array;
  return false;
}
//矩阵中的路径
void test08()
{
  vector<vector<char>> board = 
  { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
  bool ans =  exist(board, "ABCCED");
  cout << "矩阵中的路径" << endl;
  cout << ans << endl;
}
//剪绳子
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
//剪绳子
void test09()
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
void test10()
{
  cout << "剪绳子II" << endl;
  cout << cuttingRope2(555) << endl;
}
//二进制中1的个数
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

//二进制中1的个数
void test11()
{
  cout << "二进制中1的个数" << endl;
  cout << hammingWeight(8191) << endl;
}

//数值的整数次方
double myPow(double x, int n)
{
  if (n == 0)
    return 1;
  long long temp_exp = n;
  double temp_result = 1.0;
  bool flag = false;
  if (temp_exp < 0)
  {
    flag = true;
    temp_exp = -temp_exp;
  }
  while (temp_exp)
  {
    if (temp_exp & 1)
      temp_result = temp_result * x;
    x = x * x;
    temp_exp = temp_exp / 2;
  }
  return flag == true ? 1 / temp_result : temp_result;
}
//数值的整数次方
void test12()
{
  cout << "数值的整数次方" << endl;
  cout << myPow(1.5, 2) << endl;
}

//打印从1到最大的N位数
vector<int> printNumbers(int n) {
  long long num = pow(10, n) - 1;
  int* result_temp = new int[num];
  for (long long i = 0; i < num; i++)
  {
    result_temp[i] = i + 1;
  }
  vector<int> result(result_temp, result_temp + num);
  delete[] result_temp;
  return result;
}
//打印从1到最大的N位数
void test13()
{
  vector<int> ans = printNumbers(3);
  cout << "打印从1到最大的N位数" << endl;
  cout << ans[ans.size() - 1] << endl;
}
//删除链表的节点
ListNode* deleteNode(ListNode* head, int val) {
  ListNode* result = head;
  ListNode* last = head;
  if (head->val == val)
    return head->next;
  else
    head = head->next;
  while (head != nullptr)
  {
    if (head->val == val)
    {
      last->next = head->next;
      return result;
    }
    else
    {
      last = head;
      head = head->next;
    }

  }
  return result;
}
//删除链表的节点
void test14()
{
  ListNode A(1), B(2), C(3), D(4);
  A.next = &B;
  B.next = &C;
  C.next = &D;
  ListNode* ans = deleteNode(&A, 2);
  cout << "删除链表的节点" << endl;
  while (ans != nullptr)
  {
    cout << ans->val;
    ans = ans->next;
  }
}
//调整数组顺序使奇数位于偶数前面
vector<int> exchange(vector<int>& nums)
{
  vector<int> single, dual;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] % 2 == 0)
      dual.push_back(nums[i]);
    else
      single.push_back(nums[i]);
  }
  vector<int> ans;
  ans.insert(ans.end(), single.begin(), single.end());
  ans.insert(ans.end(), dual.begin(), dual.end());
  return ans;
}

//调整数组顺序使奇数位于偶数前面
void test15()
{
  vector<int> A = { 1,2,3,4,5,6,7,8 };
  vector<int>ans = exchange(A);
  cout << "调整数组顺序使奇数位于偶数前面" << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
  }
}
//链表中的倒数第K个节点
ListNode* getKthFromEnd(ListNode* head, int k)
{
  ListNode* result = head;
  int len = 0;
  while (head->next != nullptr)
  {
    len++;
    head = head->next;
  }
  for (int i = 0; i < len - k + 1; i++)
  {
    result = result->next;
  }
  return result;
}

//链表中倒数第K个节点
void test16()
{
  ListNode A(1), B(2), C(3), D(4);
  A.next = &B;
  B.next = &C;
  C.next = &D;
  ListNode* ans = getKthFromEnd(&A, 1);
  cout << "链表中的第K个节点" << endl;
  cout << ans->val << endl;
}

//反转链表
ListNode* reverseList(ListNode* head)
{
  ListNode* result = nullptr;
  ListNode* last = nullptr;
  ListNode* header = new ListNode(0);
  header->next = head;
  while (header->next != nullptr)
  {
    result = new ListNode(header->next->val);
    result->next = last;
    last = result;
    header = header->next;
  }
  return result;
}
//反转链表
void test17()
{
  ListNode A(1), B(2), C(3), D(4);
  A.next = &B;
  B.next = &C;
  C.next = &D;
  ListNode* ans = reverseList(&A);
  cout << "反转链表" << endl;
  while (ans!=nullptr)
  {
    cout << ans->val << endl;
    ans = ans->next;
  }
}

//合并两个排序的链表
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
//  ListNode* header1 = new ListNode(0);
//  header1->next = l1;
//  ListNode* header2 = new ListNode(0);
//  header2->next = l2;
//  ListNode* result  = header1;
//  ListNode* p = nullptr;
//  while (header1->next != nullptr)
//  {
//    while (header2->next != nullptr)
//    {
//      if(header1->next)
//    }
//  }
//}

//连续子数组的最大和
int maxSubArray(vector<int>& nums)
{
  int n = nums.size();
  if (n == 0)
    return 0;
  int* F = new int[n];
  F[0] = nums[0];
  int a = 0, b = 0;
  for (int i = 1; i < n; i++)
  {
    if (F[i - 1] > 0)
      F[i] = F[i - 1] + nums[i];
    else
      F[i] = nums[i];
  }
  int max = F[0];
  for (int i = 0; i <n; i++)
  {
    if (max < F[i])
      max = F[i];
  }
  return max;
}

//连续子数组的最大和
void test18()
{
  vector<int> A = { -2,1,-3,4,-1,2,1,-5,4 };
  cout << "连续子数组的最大和" << endl;
  int ans = maxSubArray(A);
  cout << ans << endl;
}

//第一个只出现一次的字符
char firstUniqChar(string s)
{
  int n = s.size();
  if (n == 0)
    return ' ';
  
  for (int i = 0; i < s.size(); i++)
  {
    int posi = s.find(s[i]);
    if (s.find(s[i], posi+1) == -1)
      return s[i];
  }
  return ' ';
}
//第一个只出现一次的字符
void test19()
{
  char ans = firstUniqChar("abaccdeff");
  cout << "第一个只出现一次的字符" << endl;
  cout << ans << endl;
}
//在排序中查找数字出现个数
int serch(vector<int>& nums, int target)
{
  int n = nums.size();
  if (n == 0)
    return 0;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (target == nums[i])
      count++;
  }
  return count;
}

//在排序中查找数字出现个数
void test20()
{
  vector<int> A = { 5,7,7,8,8,10 };
  int ans = serch(A, 8);
  cout << "在排序中查找数字出现个数" << endl;
  cout << ans << endl;
}

//0~n中缺失的数字
int missingNumber(vector<int>& nums)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    if (nums[i] != i)
      return i;
  }
  return n;
}

//0~n中缺失的数字
void test21()
{
  vector<int> A = { 0,1,2,3,4,5,7 };
  int ans = missingNumber(A);
  cout << "0~n中缺失的数字" << endl;
  cout << ans << endl;
}

//和为s的两个数字
vector<int> twoSum(vector<int>& nums, int target)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<int> ans;
  int i = 0;
  int j = n - 1;
  while(nums[i] + nums[j] != target)
  {
    if (nums[i] + nums[j] > target)
      j--;
    else
      i++;
  }
  ans.push_back(nums[i]);
  ans.push_back(nums[j]);
  return ans;
}

//和为s的两个数字
void test22()
{
  vector<int> A = { 10,26,30,31,47,60 };
  vector<int> ans = twoSum(A, 40);
  cout << "和为s的两个数字" << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
  }
}

//和为s的连续正数序列
vector<vector<int>> findContinuousSequence(int target)
{
  vector<vector<int>> ans;
  vector<int> temp;
  double n = 0.0;
  int max = (sqrt(8 * target + 1) - 1) / 2;
  int flag = 0;
  for (int m = max; m >= 2; m--)
  {
    n = 0.0;
    n =  ((2.0 * target / m) + 1.0 - m) / 2.0;
    if (round(n) == n)
    {
      temp.clear();
      for (int i = 0; i < m; i++)
        temp.push_back(n + i);
      ans.push_back(temp);
    }
  }
  return ans;
}

//和为s的连续正数序列
void test23()
{
  vector<vector<int>> ans = findContinuousSequence(15);
  cout << "和为s的连续正数序列" << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << endl;
    }
  }
}

//翻转单词顺序
string reverseWords(string s)
{
  stringstream ss(s);
  string str;
  vector<string> box;
  if (s == "")
    return "";
  while (!ss.eof())
  {
    str.clear();
    ss >> str;
    if (str == "")
      continue;
    box.push_back(str);
  }
  if (box.size() == 0)
    return "";
  str.clear();
  for (int i = box.size() - 1; i > 0; i--)
  {
    str += box[i];
    str += " ";
  }
  str += box[0];
  return str;
}
//翻转单词顺序
void test24()
{
  string A("    hello world! ");
  string ans = reverseWords(A);
  cout << "翻转单词顺序" << endl;
  cout << ans << endl;
}

//左旋转字符串
string reverseLeftWords(string s, int n)
{
  stringstream ss;
  int len = s.size();
  for (int i = n; i < len; i++)
  {
    ss << s[i];
  }
  for (int i = 0; i < n; i++)
  {
    ss << s[i];
  }
  return ss.str();
}

//左旋转字符串
void test25()
{
  string ans = reverseLeftWords("abcdefg", 2);
  cout << "左旋转字符串" << endl;
  cout << ans << endl;
}

//滑动窗口的最大值
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
  vector<int> sum;
  int len = nums.size();
  if (len == 0 || k == 0)
    return sum;
  int temp = 0;
  for (int i = 0; i < len - k + 1; i++)
  {
    temp = nums[i];
    for (int j = i; j < i + k; j++)
    {
      if (temp < nums[j])
        temp = nums[j];
    }
    sum.push_back(temp);
  }
  return sum;
}

//滑动窗口的最大值
void test26()
{
  vector<int> A = { 1,3,-1,-3,5,3,6,7 };
  vector<int> ans = maxSlidingWindow(A, 3);
  cout << "滑动窗口的最大值" << endl;
  for (int i : ans)
    cout << i << endl;
}

//扑克牌中的顺子
bool isStraight(vector<int>& nums)
{
  sort(nums.begin(), nums.end());
  int zero_num = 0;
  for (int i = 0; i < nums.size() - 1; i++)
  {
    if (nums[i] == 0)
    {
      zero_num++;
    }
    if (nums[i] == nums[i + 1] && nums[i] != 0)
      return false;
  }
  if (zero_num >= 4)
    return true;
  int e = nums[nums.size() - 1] - nums[zero_num] - 1 - 5 + zero_num + 2;
  if (e <= zero_num)
    return true;
  else
    return false;
}

//扑克牌中的顺子
void test27()
{
  vector<int> A = { 1,0,0,2,5 };
  bool ans = isStraight(A);
  cout << ans << endl;
}

int main()
{
  //test01();
  //test02();
  //test03();
  //test04();
  //test05();
  //test06();
  //test07();
  //test08();
  //test09();
  //test10();
  //test11();
  //test12();
  //test13();
  //test14();
  //test15();
  //test16();
  //test17();
  //test18();
  //test19();
  //test20();
  //test21();
  //test22();
  //test23();
  //test24();
  //test25();
  //test26();
  test27();
  return 0;
}