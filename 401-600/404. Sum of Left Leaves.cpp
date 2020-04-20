//http://www.cnblogs.com/grandyang/p/5923559.html
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root||(!root->left&&!root->right)) return 0;
        int res=0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* t = s.top();
            s.pop();
            if(t->left&&!t->left->left&&!t->left->right) res += t->left->val;
            if(t->left) s.push(t->left);
            if(t->right) s.push(t->right);
        }
        return res;
    }
};
