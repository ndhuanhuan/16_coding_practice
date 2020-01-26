// https://zxi.mytechroad.com/blog/tree/leetcode-1325-delete-leaves-with-a-given-value/
class Solution {
public:
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (!root) return nullptr;        
    root->left = removeLeafNodes(root->left, target);        
    root->right = removeLeafNodes(root->right, target);  
    return root->left || root->right || root->val != target 
      ? root : nullptr;
  }
};
