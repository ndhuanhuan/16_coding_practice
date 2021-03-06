
// https://zxi.mytechroad.com/blog/tree/leetcode-1530-number-of-good-leaf-nodes-pairs/
class Solution {
public:
  int countPairs(TreeNode* root, int distance) {
    unordered_map<TreeNode*, TreeNode*> parents;
    vector<TreeNode*> leaves;
    function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* c, TreeNode* p) {
      if (!c) return;
      parents[c] = p;      
      dfs(c->left, c);
      dfs(c->right, c);
      if (!c->left && !c->right) leaves.push_back(c);
    };
    dfs(root, nullptr);
    unordered_map<TreeNode*, int> a;
    auto isGood = [&](TreeNode* n) -> int {
      for (int i = 0; i < distance && n; ++i, n = parents[n])
        if (a.count(n) && a[n] + i <= distance) return 1;
      return 0;
    };
    int ans = 0;
    for (int i = 0; i < leaves.size(); ++i) {
      TreeNode* n1 = leaves[i];
      a.clear();
      for (int k = 0; k < distance && n1; ++k, n1 = parents[n1])
        a[n1] = k;
      for (int j = i + 1; j < leaves.size(); ++j)
        ans += isGood(leaves[j]);
    }
    return ans;
  }
};
