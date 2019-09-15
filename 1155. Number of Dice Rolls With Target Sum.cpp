// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1155-number-of-dice-rolls-with-target-sum/
class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    constexpr int kMod = 1e9 + 7;
    vector<vector<int>> dp(d + 1, vector<int>(target + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= d; ++i)
      for (int j = 1; j <= f; ++j)
        for (int k = j; k <= target; ++k)
          dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % kMod;
    return dp[d][target];
  }
};
