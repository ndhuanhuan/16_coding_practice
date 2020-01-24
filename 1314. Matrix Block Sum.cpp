// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1314-matrix-block-sum/
class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    const int n = mat.size();
    const int m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int y = 1; y <= n; ++y)
      for (int x = 1; x <= m; ++x)
        dp[y][x] = dp[y - 1][x] + dp[y][x - 1] + mat[y - 1][x - 1] - dp[y - 1][x - 1];
    auto ans = mat;
    for (int y = 1; y <= n; ++y)
      for (int x = 1; x <= m; ++x) {
        int x1 = max(1, x - K);
        int x2 = min(m, x + K);
        int y1 = max(1, y - K);
        int y2 = min(n, y + K);
        ans[y - 1][x - 1] = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
      }
    return ans;
  }
};
