// https://zxi.mytechroad.com/blog/tree/leetcode-1382-balance-a-binary-search-tree/
class Solution {
public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> vals;
    function<void(TreeNode*)> inorder = [&](TreeNode* root) {
      if (!root) return;
      inorder(root->left);
      vals.push_back(root->val);
      inorder(root->right);
    };
    
    function<TreeNode*(int, int)> build = [&](int l, int r) {
      if (l > r) return (TreeNode*)nullptr;
      int m = l + (r - l) / 2;
      auto root = new TreeNode(vals[m]);
      root->left = build(l, m - 1);
      root->right = build(m + 1, r);
      return root;
    };
    
    inorder(root);
    return build(0, vals.size() - 1);
  }
};
