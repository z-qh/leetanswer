

namespace bintreePro {
  class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
  //�ݹ������������ǰ�����
  void seekBinTree(TreeNode* node)
  {
    cout << node->val << endl;
    if (node->left != nullptr)
      seekBinTree(node->left);
    if (node->right != nullptr)
      seekBinTree(node->right);
  }
  //�ж������Ƿ���ͬ���ݹ�
  bool same(TreeNode* A, TreeNode* B)
  {
    if (A == nullptr && B == nullptr)
      return true;
    if (A == nullptr)
      return false;
    if (B == nullptr)
      return true;
    if (A->val == B->val && same(A->left, B->left) && same(A->right, B->right))
      return true;
    else
      return false;
  }
  //�ж��������ݹ�
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == nullptr)
      return false;
    if (B == nullptr)
      return false;
    if (A->val == B->val && same(A->left, B->left) && same(A->right, B->right))
      return true;
    if (A->left != nullptr && isSubStructure(A->left, B))
      return true;
    if (A->right != nullptr && isSubStructure(A->right, B))
      return true;
    return false;
  }
  /*
  * ��α��������������
  */
  bool isSubStructure2(TreeNode* A, TreeNode* B)
  {
    if (A == nullptr)
      return false;
    if (B == nullptr)
      return false;
    queue<TreeNode*> q;
    q.push(A);
    while (!q.empty())
    {
      if (q.front()->left != nullptr)
        q.push(q.front()->left);
      if (q.front()->right != nullptr)
        q.push(q.front()->right);
      if (q.front()->val == B->val && same(q.front(), B))
        return true;
      q.pop();
    }
    return false;
  }

  /*
  * ��������������
  * �ݹ�ʱ�����ҽ���
  */
  bool isMirror(TreeNode* A, TreeNode* B)
  {
    if (A == NULL && B == NULL)
      return true;
    if (A == NULL)
      return false;
    if (B == NULL)
      return false;
    if (A->val == B->val && isMirror(A->left, B->right) && isMirror(A->right, B->left))
      return true;
    return false;
  }

  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
      return true;
    return isMirror(root->left, root->right);
    
  }


  /*
  * ��α�������¼ÿһ�������
  * ���������ּ�¼����Ľڵ����һ����ӽ����Ľڵ�
  */
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == NULL)
      return vector<vector<int>>();
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> temp;
    int now_conut = 1;
    int next_conut = 0;
    while (!q.empty())
    {
      temp.push_back(q.front()->val);
      cout << q.front()->val << endl;
      if (q.front()->left != NULL) {
        next_conut++;
        q.push(q.front()->left);
      }
      if (q.front()->right != NULL) {
        next_conut++;
        q.push(q.front()->right);
      }
      now_conut--;
      if (now_conut == 0)
      {
        now_conut = next_conut;
        next_conut = 0;
        result.push_back(temp);
        temp.clear();
      }
      q.pop();
    }
    return result;
  }

  /*
  * ��α����������
  */
  int maxDepth(TreeNode* root) {
    if (root == NULL)
      return 0;
    queue<TreeNode*> q;
    q.push(root);
    int count = 0;
    int now_conut = 1;
    int next_conut = 0;
    while (!q.empty())
    {
      if (q.front()->left != NULL) {
        next_conut++;
        q.push(q.front()->left);
      }
      if (q.front()->right != NULL) {
        next_conut++;
        q.push(q.front()->right);
      }
      now_conut--;
      if (now_conut == 0)
      {
        now_conut = next_conut;
        next_conut = 0; 
        count++;
      }
      q.pop();
    }
    return count;
  }

  /*
  * ����������ת�����˫������leftָ��һ����rightָ��һ��
  */
  TreeNode* treeToDoublyList(TreeNode* root) {
    if (root == NULL)
      return NULL;
    TreeNode* A = treeToDoublyList(root->left);
    TreeNode* B = treeToDoublyList(root->right);
    if (A == NULL && B == NULL)
      return root;
    else if (A != NULL && B != NULL) {
      root->right = B;
      root->left = A->left;
      TreeNode* Bend = B->left;
      TreeNode* Aend = A->left;
      B->left = root;
      Aend->right = root;
      Bend->right = A;
      A->left = Bend;
      return A;
    }
    else if (A != NULL) {
      root->left->right = root;
      root->right = root->left;
      return root->left;
    }
    else {
      root->left = root->right;
      root->right->left = root;
      return root;
    }
  }


}
