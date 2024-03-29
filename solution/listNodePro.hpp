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

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
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

//寻找两个链表的第一个公共节点
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
  ListNode* A(0);
  A->next = headA;
  ListNode* B(0);
  B->next = headB;
  while (A->next != NULL || B->next!=NULL)
  {
    if (A->next->val == B->next->val)
      return A->next;
    A = A->next;
    B = B->next;
  }
}

void test52()
{
  getIntersectionNode(NULL, NULL);
}

/*
* 复杂链表的复制
* 依赖于现有链表结构构造节点之后再将新节点分离出来
*/
Node* copyRandomList(Node* head) {
  Node* A = head;
  if (A == NULL)
    return NULL;
  while (A != NULL)
  {
    Node* temp = A->next;
    A->next = new Node(A->val);
    A->next->next = temp;
    A = A->next->next;
  }
  A = head;
  while (A != NULL)
  {
    if (A->random != NULL) {
      A->next->random = A->random->next;
    }
    else {
      A->next->random = NULL;
    }
    A = A->next->next;
  }
  A = head;
  Node* C = head->next;
  Node* result = C;
  while (A != NULL)
  {
    Node* temp = A->next;
    A->next = A->next->next;
    C = temp;
    C->next = C->next == NULL ? NULL : A->next->next;
    A = A->next;
  }
  return result;
}

