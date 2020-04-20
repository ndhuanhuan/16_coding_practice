//https://zxi.mytechroad.com/blog/tree/leetcode-919-complete-binary-tree-inserter/
class CBTInserter {
public:
  CBTInserter(TreeNode* root): root_(root), d_({root}) {}
 
  int insert(int v) {    
    while (!d_.empty()) {
      TreeNode* r = d_.front();
      if (r->left && r->right) {
        d_.push_back(r->left);
        d_.push_back(r->right);
        d_.pop_front();
      } else if (r->left) {
        r->right = new TreeNode(v);
        return r->val;
      } else {
        r->left = new TreeNode(v);        
        return r->val;
      }
    }
  }
 
  TreeNode* get_root() { return root_; }
private:
  std::deque<TreeNode*> d_;
  TreeNode* root_;
};


vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i < tree.size();++i) {
            if (tree[i]->left) tree.push_back(tree[i]->left);
            if (tree[i]->right) tree.push_back(tree[i]->right);
        }
    }

    int insert(int v) {
        int N = tree.size();
        TreeNode* node = new TreeNode(v);
        tree.push_back(node);
        if (N % 2)
            tree[(N - 1) / 2]->left = node;
        else
            tree[(N - 1) / 2]->right = node;
        return tree[(N - 1) / 2]->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }
