#include <iostream>
#include <vector>
#include <list>

/*
* 关于图的结构问题，
* 碰到问题时构建合适的数据结构而不是局限于一个数据结构
*/

namespace grapgPro {
  /*
  * 拓扑排序
  * 入度比较重要，出度无所谓，找到入读为零后重置索引就能按照字典最小输出
  * 图的搜索树的后序遍历，反转后即为拓扑排序
  * 只能面向有向无环图
  * 输入输出的接口需要好好弄一下
  */
  class graph {
  public:
    int inDegree = 0;
    int visit = 0;
    vector<int> next;
  };
  void testTopoSort()
  {
    vector<int> firstInput = { 4 ,3 };
    vector<vector<int>> data = {
      {3, 1, 2, 3},
      {2, 2, 3},
      {2, 1, 4}
    };
    vector<graph> A(firstInput[0]);
    for (int i = 0; i < data.size(); i++)
    {
      for (int j = 1; j < data[i][0] + 1; j++)
      {
        if (j == 1)
        {
          A[data[i][j] - 1].inDegree += j - 1;
          for (int k = j + 1; k < data[i][0] + 1; k++)
          {
            A[data[i][j] - 1].next.push_back(data[i][k] - 1);
          }
        }
        else
        {
          A[data[i][j] - 1].inDegree += 1;
        }
      }
    }
    vector<int> ans;
    int i = 0;
    int count = 0;
    while (count != A.size())
    {
      if (A[i].inDegree == 0 && A[i].visit == 0) {
        ans.push_back(i);
        for (int j = 0; j < A[i].next.size(); j++)
        {
          A[A[i].next[j]].inDegree--;
        }
        count++;
        A[i].visit = 1;
        i = 0;
        continue;
      }
      i++;
      i = i % A.size();
    }

    for (int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] + 1 << endl;
    }
  }
  /*
  * 判断有向图是否存在环
  * 根据入度来选择，入度为零的遍历掉，如果遍历到最后发现无法排除所有元素，那么存在环状
  * 更简单直接的思路是深度遍历每一个节点，看看是否又数据第二次出现过，需要DFS过后的数据结构
  */



}