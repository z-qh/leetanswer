#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

//数组中重复的数字
int findRepeatNumber(vector<int>& nums)
{
  size_t len = nums.size();
  sort(nums.begin(), nums.end());
  for (int i = 0; i < len; i++)
  {
    if (nums[i] == nums[i + 1])
      return nums[i];
  }
  return nums[len - 1];
}
//数组中重复的数字
void test03()
{
  vector<int> A = { 2,2,1,3,6,7,88,14 };
  int ans = findRepeatNumber(A);
  cout << "重复的数字：" << endl;;
  cout << ans << endl;
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
void test11()
{
  vector<int> A = { 3, 4, 5, 1, 2 };
  int ans = minArray(A);
  cout << "旋转数组的最小数字" << endl;
  cout << ans << endl;
}
//圆圈中最后剩下的数字
int lastRemaining(int n, int m)
{
  int num = 0;
  for (int i = n; i >0 ; i--)
  {
    num = (num + n) % n;
  }
  return num;
}
//圆圈中最后剩下的数字
void test62()
{
  cout << "圆圈中最后剩下的数字" << endl;
  cout << lastRemaining(21, 11) << endl;
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
void test61()
{
  vector<int> A = { 1,0,0,2,5 };
  bool ans = isStraight(A);
  cout << ans << endl;
}
//打印从1到最大的N位数
vector<int> printNumbers(int n) {
  long long num = (long long)pow(10, n) - 1;
  int* result_temp = new int[num];
  for (long long i = 0; i < num; i++)
  {
    result_temp[i] = (int)i + 1;
  }
  vector<int> result(result_temp, result_temp + num);
  delete[] result_temp;
  return result;
}
//打印从1到最大的N位数
void test17()
{
  vector<int> ans = printNumbers(3);
  cout << "打印从1到最大的N位数" << endl;
  cout << ans[ans.size() - 1] << endl;
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
void test16()
{
  cout << "数值的整数次方" << endl;
  cout << myPow(1.5, 2) << endl;
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
void test15()
{
  cout << "二进制中1的个数" << endl;
  cout << hammingWeight(8191) << endl;
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
void test21()
{
  vector<int> A = { 1,2,3,4,5,6,7,8 };
  vector<int>ans = exchange(A);
  cout << "调整数组顺序使奇数位于偶数前面" << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
  }
}
//在排序数组中查找数字
int serch(vector<int>& nums, int target)
{
  size_t n = nums.size();
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
//在排序数组中查找数字
void test53I()
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
void test53II()
{
  vector<int> A = { 0,1,2,3,4,5,7 };
  int ans = missingNumber(A);
  cout << "0~n中缺失的数字" << endl;
  cout << ans << endl;
}
//和为s的两个数字
vector<int> twoSum(vector<int>& nums, int target)
{
  size_t n = nums.size();
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
void test57()
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
  int n;
  int max = (int)(sqrt(8 * target + 1) - 1) / 2;
  int flag = 0;
  for (int m = max; m >= 2; m--)
  {
    n =  (int)(((2.0 * target / m) + 1.0 - m) / 2.0);
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
void test57II()
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