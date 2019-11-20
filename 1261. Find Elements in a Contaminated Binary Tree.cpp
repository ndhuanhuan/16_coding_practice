
class FindElements {
public:
    unordered_set<int> nums;
    FindElements(TreeNode* root) {
        queue<TreeNode*> q;
        root->val=0;
        q.push(root);
        while(!q.empty()) {
            TreeNode* r=q.front();
            q.pop();
            nums.insert(r->val);
            if(r->left!=NULL) {
                r->left->val=r->val*2+1;
                q.push(r->left);
            }
            if(r->right!=NULL) 
            {
                r->right->val=r->val*2+2;
                q.push(r->right);
            }
        }
    }
    
    bool find(int target) {
        return nums.find(target)!=nums.end();
    }
};
