//http://www.cnblogs.com/grandyang/p/4251757.html
//http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-postorder-traversal.html
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *head = root;
        while (!s.empty()) {
            TreeNode *top = s.top();
            if ((!top->left && !top->right) || top->left == head || top->right == head) {
                res.push_back(top->val);
                s.pop();
                head = top;
            } else {
                if (top->right) s.push(top->right);
                if (top->left) s.push(top->left);
            }
        }
        return res;
    }
};
