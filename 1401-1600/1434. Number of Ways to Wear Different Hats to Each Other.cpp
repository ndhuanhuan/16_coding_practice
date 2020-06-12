// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1434-number-of-ways-to-wear-different-hats-to-each-other/
class Solution {
public:
  int numberWays(vector<vector<int>>& hats) {
    constexpr int kHat = 40;
    constexpr int kMod = 1e9 + 7;
    const int n = hats.size();    
    vector<vector<int>> people(kHat + 1); // hat -> {people}
    for (int i = 0; i < n; ++i)
      for (int hat : hats[i])
        people[hat].push_back(i);
    // dp[i][j] := # of ways using first i hats where j is bit mask of people wearing hats.
    vector<vector<int>> dp(kHat + 1, vector<int>(1 << n));
    dp[0][0] = 1;
    
    for (int i = 1; i <= kHat; ++i) {
      dp[i] = dp[i - 1];
      for (int mask = (1 << n) - 1; mask >= 0; --mask)
        for (int p : people[i]) {
          if (mask & (1 << p)) continue;
          dp[i][mask | (1 << p)] += dp[i - 1][mask];
          dp[i][mask | (1 << p)] %= kMod;          
        }
    }
    return dp.back().back();
  }
};
