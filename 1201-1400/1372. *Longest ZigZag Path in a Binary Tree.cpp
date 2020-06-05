// https://zxi.mytechroad.com/blog/tree/leetcode-1372-longest-zigzag-path-in-a-binary-tree/
// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/discuss/531867/JavaPython-DFS-Solution
class Solution {
public:
  int longestZigZag(TreeNode* root) {    
    return get<2>(ZigZag(root));
  }
    
  // Returns {left, right, max}
  tuple<int, int, int> ZigZag(TreeNode* root) {
    if (!root) return {-1, -1, -1};
    auto [ll, lr, lm] = ZigZag(root->left);  // lr means, currently taking left, deeper node taking right(since index is 1)
    auto [rl, rr, rm] = ZigZag(root->right); // rl means currently taking right, deeper node taking left
    int l = lr + 1;
    int r = rl + 1;
    return {l, r, max({l, r, lm, rm})};
  }
};
