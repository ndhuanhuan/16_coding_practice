//https://zxi.mytechroad.com/blog/tree/leetcode-988-smallest-string-starting-from-leaf/
class Solution {
public:
  string smallestFromLeaf(TreeNode* root) {
    if (!root) return "|"; // '|' > 'z'
    const char v = static_cast<char>('a' + root->val);
    if (!root->left && !root->right) return string(1, v);
    string l = smallestFromLeaf(root->left);    
    string r = smallestFromLeaf(root->right);    
    return min(l, r) + v;
  }
};
