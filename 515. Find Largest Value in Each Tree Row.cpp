//http://www.cnblogs.com/grandyang/p/6417826.html
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size(), mx = INT_MIN;
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front(); q.pop();
                mx = max(mx, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};
