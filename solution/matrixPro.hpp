#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>


using namespace std;

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
  size_t rows = board.size();
  if (rows == 0)
    return false;
  size_t cols = board[0].size();
  if (cols == 0)
    return false;
  size_t len = word.length();
  if (len > cols * rows)
    return false;
  if (len == 0)
    return true;
  int** used_array = new int* [rows];
  for (size_t i = 0; i < rows; i++)
    used_array[i] = new int[cols];
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      used_array[i][j] = 0;
  for (int m = 0; m < rows; m++)
    for (int n = 0; n < cols; n++)
      if (board[m][n] == word[0])
      {
        used_array[m][n] = 1;
        if (dfs(m, n, used_array, board, word, 1))
        {
          for (size_t i = 0; i < rows; i++)
            delete[] used_array[i];
          return true;
        }
        used_array[m][n] = 0;
      }
  for (size_t i = 0; i < rows; i++)
    delete[] used_array[i];
  delete[] used_array;
  return false;
}

//矩阵中的路径
void test08()
{
  vector<vector<char>> board =
  { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
  bool ans = exist(board, "ABCCED");
  cout << "矩阵中的路径" << endl;
  cout << ans << endl;
}
//BFS广度优先搜索二维数组,用之前queue先存入第一个点
void BFS(int width, int heigh, vector<vector<int>>& visited, queue<pair<int, int>>& q)
{
  //记录第一个元素的位置
  pair<int, int> posi(q.front());
  int x = posi.first, y = posi.second;
  //访问当前元素
  visited[x][y] = 1;
  cout << x << "," << y << endl;
  q.pop();
  //存入相邻的几个元素到队列中，小技巧
  vector<pair<int, int>> direct = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
  for (int i = 0; i < 4; i++)
  {
    int current_x = x + direct[i].first;
    int current_y = y + direct[i].second;
    if (current_x >= 0 && current_x < width && current_y >= 0 && current_y < heigh && visited[current_x][current_y] != 1)
    {
      q.push(make_pair(current_x, current_y));
      visited[current_x][current_y] = 1;
    }
  }
  if (q.empty() == false)
    BFS(width, heigh, visited, q);
}
//BFS广度优先搜索,用之前queue先存入第一个点
void test29()
{
  //创建地图，输入，小技巧，以后二维数组就用Vector了
  vector<vector<int>> MAP = { {0,1,2,3} , {4,5,6,7,} , {8,9,10,11} , {12,13,14,15,16} };
  //创建访问辅助空间
  vector<vector<int>> visited(4, vector<int>(4, 0));
  //创建队列辅助用
  queue<pair<int, int>> q;
  q.push(make_pair(2, 2));
  cout << "二维数组的广度优先搜索" << endl;
  BFS(4, 4, visited, q);

}