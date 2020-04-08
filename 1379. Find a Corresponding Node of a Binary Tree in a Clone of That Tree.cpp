// https://zxi.mytechroad.com/blog/tree/leetcode-1379-find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
class Solution {
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (!original) return nullptr;
    if (original == target) return cloned;
    auto l = getTargetCopy(original->left, cloned->left, target);
    auto r = getTargetCopy(original->right, cloned->right, target);
    return l ? l : r;
  }
};
