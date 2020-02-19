// https://zxi.mytechroad.com/blog/tree/leetcode-1343-maximum-product-of-splitted-binary-tree/
class Solution {
public:
  int maxProduct(TreeNode* root) {
    const int kMod = 1e9 + 7;    
    long s = 0;    
    long ans = 0;    
    function<int(TreeNode*)> sum = [&](TreeNode* r) {
      if (!r) return 0;
      int sl = sum(r->left);
      int sr = sum(r->right);      
      if (s) ans = max({ans, (s - sl) * sl, (s - sr) * sr});
      return r->val + sl + sr;
    };
    s = sum(root);
    sum(root);    
    return ans % kMod;
  }  
};
