// https://zxi.mytechroad.com/blog/tree/leetcode-1373-maximum-sum-bst-in-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, &ans);
        return ans;
    }
    
    // returns {lo, hi, sum, valid_bst}
    tuple<int, int, int, bool> dfs(TreeNode* root, int* ans) {
        if(!root) return {INT_MAX, INT_MIN, 0, true};
        auto [ll, lh, ls, lv] = dfs(root->left, ans);
        auto [rl, rh, rs, rv] = dfs(root->right, ans);
        bool valid = root->val > lh && root->val < rl && lv && rv;
        int sum = valid ? root->val + ls + rs : -1;
        *ans = max(*ans, sum);
        return {min(root->val, ll), max(root->val, rh), sum, valid};
    }
};
