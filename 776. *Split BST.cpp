// https://www.cnblogs.com/grandyang/p/8993143.html
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res{NULL, NULL};
        if (!root) return res;
        if (root->val <= V) {
            res = splitBST(root->right, V);
            root->right = res[0];  //only right has possibility that value greater than V
            res[0] = root;
        } else {
            res = splitBST(root->left, V);
            root->left = res[1];
            res[1] = root;
        }
        return res;
    }
};
