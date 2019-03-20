// https://leetcode.com/problems/increasing-order-search-tree/discuss/165885/C%2B%2BJavaPython-Self-Explained-5-line-O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};


// https://zxi.mytechroad.com/blog/tree/leetcode-897-increasing-order-search-tree/
class Solution {
public:
  TreeNode* increasingBST(TreeNode* root) {
    TreeNode dummy(0);
    prev_ = &dummy;
    inorder(root);
    return dummy.right;
  }
private:  
  TreeNode* prev_;
  void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    prev_->right = root;  
    prev_ = root;
    prev_->left = nullptr;
    inorder(root->right);
  }
};
