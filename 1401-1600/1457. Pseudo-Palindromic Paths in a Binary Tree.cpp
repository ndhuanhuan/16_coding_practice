// https://zxi.mytechroad.com/blog/uncategorized/leetcode-1457-pseudo-palindromic-paths-in-a-binary-tree/
class Solution {
public:
  int pseudoPalindromicPaths(TreeNode* root, int s = 0) {    
    if (!root) return 0;
    s ^= (1 << root->val);
    if (!root->left && !root->right)
      return __builtin_popcount(s) <= 1;
    return pseudoPalindromicPaths(root->left, s) 
         + pseudoPalindromicPaths(root->right, s);          
  }
};
