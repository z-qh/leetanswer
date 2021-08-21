#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>


namespace sectionPro {


  bool com(pair<int, int>A, pair<int, int>B)
  {
    return A.first < B.first;
  }

  pair<int, int> over(pair<int, int>A, pair<int, int>B)
  {
    if (A.first == B.second)
    {
      int max = A.second > B.second ? A.second : B.second;
      return make_pair(A.first, max);
    }
    if (A.second < B.first)
      return make_pair(0, 0);
    else if (A.second <= B.second)
      return make_pair(A.first, B.second);
    else if (A.second >= B.second)
      return make_pair(A.first, A.second);
  }
  /*
  * 题目
  * 游戏buff持续的开始时间由第一个数字给出，持续时间由第二个数字给出
  * 统计玩家身上存在游戏buff的总时间
  */
  void testSection()
  {
    vector<pair<int, int>> data{ {10,2},{51,3},{45,16},{18,20} };
    pair<int, int> zero(0, 0);
    sort(data.begin(), data.end(), com);
    for (int i = 0; i < data.size(); i++)
    {
      data[i].second += data[i].first;
    }
    int time = 0;
    pair<int, int> last(data.front().first, data.front().second);
    for (int i = 0; i < data.size() - 1; i++)
    {
      pair<int, int> temp = over(last, data[i + 1]);
      if (temp == zero)
      {
        time += (last.second - last.first);
        last = data[i + 1];
      }
      else
        last = temp;
    }
    time += last.second - last.first;
    cout << time << endl;
  }
}

