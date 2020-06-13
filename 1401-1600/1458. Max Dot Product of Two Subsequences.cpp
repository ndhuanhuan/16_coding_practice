// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1458-max-dot-product-of-two-subsequences/
class Solution {
public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    // dp[i][j] = max dot product of two subsequences 
    // of nums1[0:i] and nums2[0:j]
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN / 2));
        
    for (int i = 1; i <= n1; ++i)
      for (int j = 1; j <= n2; ++j)
        dp[i][j] = max({
          dp[i - 1][j],
          dp[i][j - 1],
          max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1]
        });
    return dp[n1][n2];
  }
};
