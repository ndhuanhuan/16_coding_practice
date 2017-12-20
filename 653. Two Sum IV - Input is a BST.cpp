class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> s;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
          auto t = q.front(); q.pop();
          if (s.count(k - t->val)) return true;
          s.insert(t->val);
          if (t->left) q.push(t->left);
          if (t->right) q.push(t->right);
        }
        return false;
    }
};
