#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

//二维数组中的查找
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
  size_t rows = matrix.size();
  if (rows == 0)
    return false;
  size_t cols = matrix[0].size();
  if (cols == 0)
    return false;
  for (size_t i = 0; i < rows; i++)
  {
    if (matrix[i][0] <= target && matrix[i][cols - 1] >= target)
    {
      for (size_t j = 0; j < cols; j++)
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
void test04()
{
  vector<vector<int>> A = 
  { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
  bool ans = findNumberIn2DArray(A, 5);
  cout << "二维数组中的查找" << endl;
  cout << ans << endl;
}