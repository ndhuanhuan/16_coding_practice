//http://www.cnblogs.com/grandyang/p/4738031.html
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) dfs(root, "", res);
        return res;
    }
    void dfs(TreeNode *root, string out, vector<string> &res) {
        out += to_string(root->val);
        if (!root->left && !root->right) res.push_back(out);
        else {
            if (root->left) dfs(root->left, out + "->", res);
            if (root->right) dfs(root->right, out + "->", res);
        }
    }
};
