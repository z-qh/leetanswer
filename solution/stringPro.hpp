#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>


using namespace std;

//第一个只出现一次的字符
char firstUniqChar(string s)
{
  size_t n = s.size();
  if (n == 0)
    return ' ';
  
  for (int i = 0; i < s.size(); i++)
  {
    size_t posi = s.find(s[i]);
    if (s.find(s[i], posi+1) == -1)
      return s[i];
  }
  return ' ';
}
//第一个只出现一次的字符
void test50()
{
  char ans = firstUniqChar("abaccdeff");
  cout << "第一个只出现一次的字符" << endl;
  cout << ans << endl;
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
  for (size_t i = box.size() - 1; i > 0; i--)
  {
    str += box[i];
    str += " ";
  }
  str += box[0];
  return str;
}
//翻转单词顺序
void test58I()
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
  size_t len = s.size();
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
void test58II()
{
  string ans = reverseLeftWords("abcdefg", 2);
  cout << "左旋转字符串" << endl;
  cout << ans << endl;
}
/*
* 字符串全排列
* 根据一个排列找下一个排列
* 找一个排列中的顺序部分，将顺序部分中小的和从后往前的第一个大的交换，交换后第一个部分后面的全部取反
*/
string inverseString(string s, int i, int j)
{
  int sSize = s.size();
  int m = i;
  int n = j;
  int time = (j - i + 1) / 2;
  for (int k = 0; k < time; k++)
  {
    char temp = s[m];
    s[m] = s[j];
    s[j] = temp;
    m++;
    j--;
  }
  return s;
}

bool stringFindNext(string now, string& next)
{
  int nowSize = now.size();
  for (int i = nowSize - 1; i > 0; i--)
  {
    if (now[i] > now[i - 1])
    {
      for (int j = nowSize - 1; j > i - 1; j--)
      {
        if (now[j] > now[i-1])
        {
          char temp = now[i-1];
          now[i-1] = now[j];
          now[j] = temp;
          next = inverseString(now, i, nowSize-1);
          return true;
        }
      }
    }
  }
  return false;
}
vector<string> permutation(string s) {
  sort(s.begin(), s.end());
  vector<string> result;
  result.push_back(s);
  string next = s;
  cout << next << endl;
  bool flag = true;
  while (flag)
  {
    flag = stringFindNext(next, next);
    if (flag) {
      result.push_back(next);
      cout << next << endl;
    }
  }
  return result;
}