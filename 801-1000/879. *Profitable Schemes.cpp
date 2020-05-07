// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-879-profitable-schemes/
class Solution {
public:
  int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {    
    const int kMod = 1000000007;
    const int K = group.size();
    // dp[i][j]:= # of schemes of making profit i with j people.
    vector<vector<int>> dp(P + 1, vector<int>(G + 1, 0));
    dp[0][0] = 1;
    
    for (int k = 1; k <= K; ++k) {
      auto tmp = dp;
      const int p = profit[k - 1];
      const int g = group[k - 1];
      for (int i = 0; i <= P; ++i)    
        for (int j = 0; j <= G; ++j)
          tmp[i][j] = (tmp[i][j] + (j < g ? 0 : dp[max(0, i - p)][j - g])) % kMod;
      dp.swap(tmp);
    }
    return accumulate(begin(dp[P]), end(dp[P]), 0LL) % kMod;
  }
};
