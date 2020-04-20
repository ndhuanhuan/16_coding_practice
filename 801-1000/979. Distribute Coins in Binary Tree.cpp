//https://zxi.mytechroad.com/blog/tree/leetcode-979-distribute-coins-in-binary-tree/
class Solution {
public:
  int distributeCoins(TreeNode* root) {    
    int ans = 0;
    balance(root, ans);
    return ans;
  }
private:
  int balance(TreeNode* root, int& ans) {
    if (!root) return 0;
    int l = balance(root->left, ans);
    int r = balance(root->right, ans);
    ans += abs(l) + abs(r); 
    return l + r + root->val - 1;  //how many coins need to pass into parent
  }
};
