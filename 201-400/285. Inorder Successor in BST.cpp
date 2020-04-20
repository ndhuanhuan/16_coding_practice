//http://www.cnblogs.com/grandyang/p/5306162.html
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *res = NULL;
        while (root) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            } else root = root->right;
        }
        return res;
    }
};



class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        bool b = false;
        TreeNode *t = root;
        while (t || !s.empty()) {
            while (t) {
                s.push(t);
                t = t->left;
            }
            t = s.top(); s.pop();
            if (b) return t;
            if (t == p) b = true;
            t = t->right;
        }
        return NULL;
    }
};
