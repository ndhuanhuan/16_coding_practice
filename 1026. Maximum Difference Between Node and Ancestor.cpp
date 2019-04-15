// https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-132/
class Solution {
public:
  int maxAncestorDiff(TreeNode* root) {
    if (!root) return 0;
    return maxDiff(root, root->val, root->val);
  }
private:
  int maxDiff(TreeNode* root, int l, int r) {    //l is the minimum so far, r is maximum so far
    if (!root) return 0;
    int cur = max(abs(root->val - l), abs(root->val - r));
    l = min(l, root->val);
    r = max(r, root->val);
    return max(cur, max(maxDiff(root->left, l, r),
                        maxDiff(root->right, l, r)));
  }
};
