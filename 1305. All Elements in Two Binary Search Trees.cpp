// https://zxi.mytechroad.com/blog/tree/leetcode-1305-all-elements-in-two-binary-search-trees/
class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {    
    function<void(TreeNode*, vector<int>&)> inorder = [&](TreeNode* root, vector<int>& t) {
      if (!root) return;
      inorder(root->left, t);
      t.push_back(root->val);
      inorder(root->right, t);
    };
    vector<int> t1;
    vector<int> t2;
    inorder(root1, t1);
    inorder(root2, t2);
    vector<int> m;
    int i = 0;
    int j = 0;
    while (m.size() != t1.size() + t2.size()) {
      if (j == t2.size()) m.push_back(t1[i++]);
      else if (i == t1.size()) m.push_back(t2[j++]);
      else m.push_back(t1[i] < t2[j] ? t1[i++] : t2[j++]);      
    }
    return m;
  }
};
