//http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-preorder-traversal.html
//http://www.cnblogs.com/grandyang/p/4146981.html
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (!root) return res;
        s.push(root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            res.push_back(p->val);
            s.pop();
            if (p->right) s.push(p->right);  //push right first as it is a "stack"
            if (p->left) s.push(p->left);
        }
        return res;
    }
};
