// https://zxi.mytechroad.com/blog/tree/leetcode-865-smallest-subtree-with-all-the-deepest-nodes/
class Solution {
public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return depth(root).second;
  }
private:
  pair<int, TreeNode*> depth(TreeNode* root) {
    if (root == nullptr)
      return {-1, nullptr};
    auto l = depth(root->left);
    auto r = depth(root->right);
    int dl = l.first;
    int dr = r.first;
    return { max(dl, dr) + 1, 
             dl == dr ? root : (dl > dr) ? l.second : r.second};
  }
};
