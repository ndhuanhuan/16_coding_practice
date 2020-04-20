// https://zxi.mytechroad.com/blog/tree/leetcode-894-all-possible-full-binary-trees/
static constexpr int kMaxN = 20 + 1;
static array<vector<TreeNode*>, kMaxN> m;
 
class Solution {
public:
  vector<TreeNode*> allPossibleFBT(int N) {
    return trees(N);
  }
private:
  vector<TreeNode*>& trees(int N) {
    if (m[N].size() > 0) return m[N];
    vector<TreeNode*>& ans = m[N];
    if (N % 2 == 0) return ans = {};    
    if (N == 1) ans = {new TreeNode(0)};
    for (int i = 1; i < N; i += 2) {
      for (const auto& l : trees(i))
        for (const auto& r : trees(N - i - 1)) {
          auto root = new TreeNode(0);
          root->left = l;
          root->right = r;
          ans.push_back(root);
        }    
    }
    return ans;
  }
};
