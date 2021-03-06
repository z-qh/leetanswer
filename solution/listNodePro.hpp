#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

//从尾到头打印链表
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) :val(x), next(nullptr) {}
};
vector<int> reversePrint(ListNode* head)
{
  vector<int> result;
  while (head != nullptr)
  {
    result.insert(result.begin(), head->val);
    head = head->next;
  }
  return result;
}
//从尾到头打印链表
void test06()
{
  ListNode A(1), B(3), C(2);
  A.next = &B;
  B.next = &C;
  vector<int> ans = reversePrint(&A);
  cout << "从尾到头打印链表" << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
}
//删除链表的节点
ListNode* deleteNode(ListNode* head, int val) {
  ListNode* result = head;
  ListNode* last = head;
  if (head->val == val)
    return head->next;
  else
    head = head->next;
  while (head != nullptr)
  {
    if (head->val == val)
    {
      last->next = head->next;
      return result;
    }
    else
    {
      last = head;
      head = head->next;
    }

  }
  return result;
}
//删除链表的节点
void test18()
{
  ListNode A(1), B(2), C(3), D(4);
  A.next = &B;
  B.next = &C;
  C.next = &D;
  ListNode* ans = deleteNode(&A, 2);
  cout << "删除链表的节点" << endl;
  while (ans != nullptr)
  {
    cout << ans->val;
    ans = ans->next;
  }
}
//链表中倒数第K个节点
ListNode* getKthFromEnd(ListNode* head, int k)
{
  if (head == nullptr)
    return nullptr;
  ListNode* result = head;
  int len = 0;
  while (head->next != nullptr)
  {
    len++;
    head = head->next;
  }
  for (int i = 0; i < len - k + 1; i++)
  {
    result = result->next;
  }
  return result;
}
//链表中倒数第K个节点
void test22()
{
  ListNode A(1), B(2), C(3), D(4);
  A.next = &B;
  B.next = &C;
  C.next = &D;
  ListNode* ans = getKthFromEnd(&A, 1);
  cout << "链表中的第K个节点" << endl;
  cout << ans->val << endl;
}
//反转链表
ListNode* reverseList(ListNode* head)
{
  ListNode* result = nullptr;
  ListNode* last = nullptr;
  ListNode* header = new ListNode(0);
  header->next = head;
  while (header->next != nullptr)
  {
    result = new ListNode(header->next->val);
    result->next = last;
    last = result;
    header = header->next;
  }
  return result;
}
//反转链表
void test24()
{
  ListNode A(1), B(2), C(3), D(4);
  A.next = &B;
  B.next = &C;
  C.next = &D;
  ListNode* ans = reverseList(&A);
  cout << "反转链表" << endl;
  while (ans!=nullptr)
  {
    cout << ans->val << endl;
    ans = ans->next;
  }
}