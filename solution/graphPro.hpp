#include <iostream>
#include <vector>
#include <list>

/*
* ����ͼ�Ľṹ���⣬
* ��������ʱ�������ʵ����ݽṹ�����Ǿ�����һ�����ݽṹ
*/

namespace grapgPro {
  /*
  * ��������
  * ��ȱȽ���Ҫ����������ν���ҵ����Ϊ��������������ܰ����ֵ���С���
  * ͼ���������ĺ����������ת��Ϊ��������
  * ֻ�����������޻�ͼ
  * ��������Ľӿ���Ҫ�ú�Ūһ��
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
  * �ж�����ͼ�Ƿ���ڻ�
  * ���������ѡ�����Ϊ��ı����������������������޷��ų�����Ԫ�أ���ô���ڻ�״
  * ����ֱ�ӵ�˼·����ȱ���ÿһ���ڵ㣬�����Ƿ������ݵڶ��γ��ֹ�����ҪDFS��������ݽṹ
  */



}