//https://zxi.mytechroad.com/blog/tree/leetcode-971-flip-binary-tree-to-match-preorder-traversal/
class Solution {
public:
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> flips;
    int pos = 0;
    solve(root, voyage, pos, flips);
    return flips;
  }
private:
  void solve(TreeNode* root, const vector<int>& voyage, int& pos, vector<int>& flips) {
    if (!root) return;
    if (root->val != voyage.at(pos)) {
      flips.clear();
      flips.push_back(-1);
      return;
    }
    if (root->left && root->left->val != voyage.at(pos + 1)) {
      swap(root->left, root->right);
      flips.push_back(root->val);
    }
    ++pos;
    solve(root->left, voyage, pos, flips);
    solve(root->right, voyage, pos, flips);   
  }
};
