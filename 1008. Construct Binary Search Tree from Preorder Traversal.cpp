// https://zxi.mytechroad.com/blog/tree/leetcode-1008-construct-binary-search-tree-from-preorder-traversal/
class Solution {
public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return build(preorder, 0, preorder.size());
  }
private:
  TreeNode* build(const vector<int>& preorder, int s, int e) {
    if (s >= e) return nullptr;
    auto root = new TreeNode(preorder[s]);
    int m = s;
    while (m < e && preorder[m] <= root->val) ++m;
    root->left = build(preorder, s + 1, m);
    root->right = build(preorder, m, e);
    return root;
  }
};
