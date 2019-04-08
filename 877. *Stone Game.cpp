// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-877-stone-game/
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();
    // dp[i][j] := max(your_stones - op_stones) for piles[i] ~ piles[j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      dp[i][i] = piles[i];
    for (int l = 2; l <= n; ++l)
      for (int i = 0; i < n - l + 1; ++i) {
        int j = i + l - 1;
        dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]); // dp[i + 1][j] and dp[i][j - 1] are the best score of your opponent
      }
    return dp[0][n - 1] > 0;    
  }
};
