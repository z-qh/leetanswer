#include <queue>
#include <stack>
#include <iostream>
#include <vector>
#include <string>

namespace others {

  bool com(int A, int B)
  {
    return A > B;
  }
  /*
  * 在一个数组中寻找满足条件的数字对的个数
  * 问题数量小的时候比较好解决，二重遍历就行了
  * 数据量大的时候还是需要做一些优化，排序后查找临界点用于统计
  */
  int search(int L, int R, vector<int> data, int i)
  {
    if (i == data.size() - 1)
      return 0;
    if (data[i] + data[i + 1] > R)
      return 0;
    if (data[i] + data.back() < L)
      return 0;
    int left = i, right = data.size();
    for (int j = data.size() - 1; j >= 0; j--)
    {
      if (data[i] + data[j] <= R) {
        right = j;
        break;
      }
    }
    for (int k = i + 1; k < data.size(); k++)
    {
      if (data[i] + data[k] >= L) {
        left = k;
        break;
      }
    }
    return right - left;
  }

  void finNumPairBetween()
  {
    int n = 5, L = 0, R = 60;
    vector<int> data{ 5, 1, 2, 4, 3 };

    int sum = 0;
    sort(data.begin(), data.end());
    for (int i = 0; i < n; i++)
    {
      cout << data[i] << endl;
      if (data[i] > R)
        continue;
      sum += search(L, R, data, i);
    }
    cout << sum << endl;
  }
  /*
  * 栈的入栈出栈顺序，用模拟的方式做
  */
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> S;
    if (popped.empty() && pushed.empty())\
      return true;
    if (popped.empty())
      return false;
    if (pushed.empty())
      return false;
    if (popped.size() != pushed.size())
      return false;
    int i = 1, j = 0;
    S.push(pushed[0]);
    while (j < popped.size())
    {
      if (S.top() == popped[j]) {
        S.pop();
        if (i > pushed.size() - 1)
          return true;
        S.push(pushed[i]);
        i++;
        j++;
      }
      else {
        if (i > pushed.size() - 1)
          return false;
        S.push(pushed[i]);
        i++;
      }
    }
    return true;
  }
  bool Acom(pair<int, int> A, pair<int, int> B)
  {
    return B.second > A.second;
  }


  int memManger()
  {
    int N;
    vector<pair<int, int>> mem;
    vector<int> useM;
    int tempN, tempS;
    int useN;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
      cin >> tempN >> tempS;
      mem.push_back({ tempN, tempS });
    }
    cin >> useN;
    for (int i = 0; i < useN; i++)
    {
      cin >> tempS;
      useM.push_back(tempS);
    }
    cout << N << endl;
    for (int i = 0; i < N; i++)
    {
      cout << mem[i].first << " " << mem[i].second << endl;;
    }
    cout << useN << endl;
    for (int i = 0; i < useN; i++)
    {
      cout << useM[i] << " ";
    }
    
    sort(useM.begin(), useM.end());
    sort(mem.begin(), mem.end(), Acom);
    vector<int> rest;
    for (int i = 0; i < N; i++)
    {
      rest.push_back(mem[i].first);
    }
    vector<int> visited(useN, 0);
    for (int i = useN - 1; i >= 0; i--)
    {
      for (int j = N-1; j >=0; j--)
      {
        if (visited[i] == 0 && useM[i] <= mem[j].second && rest[j] > 0)
        {
          int restS = mem[j].second - useM[i];
          int nowS = useM[i];
          rest[j] -= 1;
          visited[i] = 1;
          if (i != 0) {
            for (int k = i - 1; k >= 0; k--)
            {
              if (visited[k] == 0 && useM[k] <= restS)
              {
                restS -= useM[k];
                nowS += useM[k];
                visited[k] = 1;
              }
            }
          }
          for (int m = 0; m < j; m++)
          {
            if (nowS <= mem[m].second && rest[m] > 0)
            {
              rest[j]++;
              rest[m]--;
              break;
            }
          }
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
      sum += rest[i] * mem[i].second;
    }
    cout << sum << endl;
    return sum;
  }

  int findNthDigit(int n) {
    if(n == 0)
      return 0;
    if (n < 10)
      return n;
    int posiN = 1 * 9 * pow(10, 0);
    int numN = 9 * pow(10, 0);
    int N = 1;
    while (n > posiN)
    {
      N++;
      posiN += N * 9 * pow(10, N - 1);
      numN += 9 * pow(10, N - 1);
    }
    cout << N << "位数" << endl;
    int lastNumN = numN - 9 * pow(10, N - 1);
    int lastPosiN = posiN - N * 9 * pow(10, N - 1);
    int diff = n - lastPosiN;
    int rest = diff % N;
    int nowPosi = diff / N + lastNumN;
    if (rest != 0) nowPosi++;
    rest = --rest % N < 0 ? N - 1 : rest;
    while (N - rest > 1)
    {
      nowPosi /= 10;
      N--;
    }
    while (rest > 0)
    {
      nowPosi %= 10;
      rest--;
    }
    return nowPosi;
  }

}