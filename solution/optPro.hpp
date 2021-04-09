#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>


using namespace std;

//滑动窗口的最大值
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
  vector<int> sum;
  size_t len = nums.size();
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
void test59I()
{
  vector<int> A = { 1,3,-1,-3,5,3,6,7 };
  vector<int> ans = maxSlidingWindow(A, 3);
  cout << "滑动窗口的最大值" << endl;
  for (int i : ans)
    cout << i << endl;
}
//连续子数组的最大和
int maxSubArray(vector<int>& nums)
{
  size_t n = nums.size();
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
void test42()
{
  vector<int> A = { -2,1,-3,4,-1,2,1,-5,4 };
  cout << "连续子数组的最大和" << endl;
  int ans = maxSubArray(A);
  cout << ans << endl;
}