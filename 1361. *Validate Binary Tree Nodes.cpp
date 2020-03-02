// https://zxi.mytechroad.com/blog/tree/leetcode-1361-validate-binary-tree-nodes/
class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<int> in(n);
    for (int l : leftChild) if (l >= 0) ++in[l];
    for (int r : rightChild) if (r >= 0) ++in[r];
    int zero = 0;
    for (int i = 0; i < n; ++i) {
      if (in[i] > 1) return false;
      if (in[i] == 0) ++zero;
    }
    // # of nodes without parent must be 1.
    return zero == 1;
  }
};
