//http://www.cnblogs.com/grandyang/p/4620012.html
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            ++cnt;
            if (cnt == k) return p->val;
            p = p->right;
        }
        return 0;
    }
};
