// https://zxi.mytechroad.com/blog/tree/leetcode-1110-delete-nodes-and-return-forest/
class Solution {
public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    unordered_set<int> s{begin(to_delete), end(to_delete)};
    function<TreeNode*(TreeNode*)> del = [&](TreeNode* n) -> TreeNode* {
      if (!n) return nullptr;
      if (n->left) n->left = del(n->left);
      if (n->right) n->right = del(n->right);
      if (!s.count(n->val)) return n;
      if (n->left) ans.push_back(n->left);
      if (n->right) ans.push_back(n->right);      
      return nullptr;
    };
    TreeNode* r = del(root);
    if (r) ans.push_back(r);
    return ans;
  }
};
