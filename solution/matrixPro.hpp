#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>


using namespace std;
//回溯
bool backTracking(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& board, string word, int n)
{
  if (n >= word.length())
    return true;
  static vector<pair<int, int>> direct = { {-1,0},{1,0},{0,-1},{0,1} };
  for (int k = 0; k < 4; k++)
  {
    int x = i + direct[k].first;
    int y = j + direct[k].second;
    int heigh = board.size();
    int width = board[0].size();
    if (x >= 0 && x < heigh && y >= 0 && y < width && visited[x][y] == 0 && board[x][y] == word[n])
    {
      visited[x][y] = 1;
      if (backTracking(x, y, visited, board, word, n + 1))
        return true;
      visited[x][y] = 0;
    }
  }
  return false;
}
//矩阵中的路径
bool exist(vector<vector<char>>& board, string word)
{
  //判空
  int heigh = board.size();
  if (heigh == 0)
    return false;
  int width = board[0].size();
  if (width == 0)
    return false;
  int len = word.length();
  if (len == 0)
    return true;
  if (len > width * heigh)
    return false;
  //辅助空间
  vector<vector<int>> visited(heigh, vector<int>(width, 0));
  for (int m = 0; m < heigh; m++)
    for (int n = 0; n < width; n++)
      if (board[m][n] == word[0])
      {
        visited[m][n] = 1;
        if (backTracking(m, n, visited, board, word, 1))
          return true;
        visited[m][n] = 0;
      }
  return false;
}
//矩阵中的路径
void test12()
{
  vector<vector<char>> board =
  { {'A', 'B'},
    {'C', 'D'}};
  bool ans = exist(board, "CDBA");
  cout << "矩阵中的路径" << endl;
  cout << ans << endl;
}
//BFS广度优先搜索二维数组，用之前queue先存入第一个点，递归，需要辅助空间
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
//BFS广度优先搜索二维数组，用之前queue先存入第一个点，递推，不需要辅助空间
void BFS(int width, int heigh, queue<pair<int, int>>& q)
{
  //构建辅助空间
  vector<vector<int>> visited(heigh, vector<int>(width, 0));
  vector<pair<int, int>> direct = { {0,1}, {1,0}, {0,-1}, {-1,0} };
  while (!q.empty())
  {
    //取出第一个元素
    pair<int, int> posi(q.front());
    int x = posi.first, y = posi.second;
    //访问第一个元素并弹出
    q.pop();
    cout << x << "," << y << endl;
    visited[x][y] = 1;
    //加入周围的元素
    for (int i = 0; i < 4; i++)
    {
      int current_x = x + direct[i].first;
      int current_y = y + direct[i].second;
      if (current_x >= 0 && current_x < width && current_y >= 0 && current_y < heigh && visited[current_x][current_y] != 1)
      {
        q.push(make_pair(current_x, current_y));
      }
    }
  }
}
//BFS广度优先搜索,用之前queue先存入第一个点
void testMatBFS()
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
  q.push(make_pair(2, 2));
  BFS(4, 4, q);

}
