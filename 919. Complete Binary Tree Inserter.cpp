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
