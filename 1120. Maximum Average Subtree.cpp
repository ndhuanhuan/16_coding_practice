// https://leetcode.com/problems/maximum-average-subtree/discuss/334152/C%2B%2B-Simple-recursive-solution
class Solution {
public:
  double maximumAverageSubtree(TreeNode* root) {
    getInfo(root);
    return maxAvg;
  }
  
private:
  double maxAvg = -1;

  struct Info {
    int count;
    double sum;
  };

  Info getInfo(TreeNode* root) {
    if (!root) return {0, 0};
    Info l = getInfo(root->left);
    Info r = getInfo(root->right);
    Info result = { l.count + r.count + 1, l.sum + r.sum + root->val };
    maxAvg = max(maxAvg, result.sum / result.count);
    return result;
  }
};
