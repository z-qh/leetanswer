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
