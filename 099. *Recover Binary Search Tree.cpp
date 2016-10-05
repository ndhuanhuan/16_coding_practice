//http://www.cnblogs.com/grandyang/p/4298069.html
//Morris->I don't know how to do it
class Solution {
public:
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;
    void recoverTree(TreeNode *root) {
        pre = NULL;
        first = NULL;
        second = NULL;
        inorder(root);
        if (first && second) swap(first->val, second->val);
    }
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (!pre) pre = root;
        else {
            if (pre->val > root->val) {
                if (!first) first = pre;
                second = root;
            }
            pre = root;
        }
        inorder(root->right);
    }
};
