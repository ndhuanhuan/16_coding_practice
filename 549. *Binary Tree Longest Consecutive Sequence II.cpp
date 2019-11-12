
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        postorder(res, root->val, root);
        return res;
    }
    pair<int, int> postorder(int& res, int pVal, TreeNode* node) {
        if (!node) return {0, 0};
        pair<int, int> left = postorder(res, node->val, node->left);
        pair<int, int> right = postorder(res, node->val, node->right);
        
        res = max(left.second + right.first + 1, res);
        res = max(left.first + right.second + 1, res);

        int inc = 0, dec = 0;
        if (node->val == pVal+1) inc = max(left.first, right.first) + 1;  // max child increase + 1
        if (node->val == pVal-1) dec = max(left.second, right.second) + 1; // max child decrease + 1
        return {inc, dec};
    }
};
