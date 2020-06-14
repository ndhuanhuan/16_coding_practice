// https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-133/
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {      
      dp[i][0] = dp[i - 1][0] + costs[i - 1][1];
      for (int j = 1; j <= i; ++j)
        dp[i][j] = min(dp[i - 1][j - 1] + costs[i - 1][0], 
                       dp[i - 1][j] + costs[i - 1][1]);
    }
    return dp[n][n / 2];
  }
};
