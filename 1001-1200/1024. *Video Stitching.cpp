// https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-131-1021-1022-1023-1024/
class Solution {
public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    constexpr int kInf = 101;
    // dp[i][j] := min clips to cover range [i, j]
    vector<vector<int>> dp(T + 1, vector<int>(T + 1, kInf));   
    for (const auto& c : clips) {
      int s = c[0];
      int e = c[1];
      for (int l = 1; l <= T; ++l) {
        for (int i = 0; i <= T - l; ++i) {
          int j = i + l;
          if (s > j || e < i) continue;
          if (s <= i && e >= j) dp[i][j] = 1;
          else if (e >= j) dp[i][j] = min(dp[i][j], dp[i][s] + 1);
          else if (s <= i) dp[i][j] = min(dp[i][j], dp[e][j] + 1);
          else dp[i][j] = min(dp[i][j], dp[i][s] + 1 + dp[e][j]);          
        }
      }
    }
    return dp[0][T] == kInf ? -1 : dp[0][T];
  }
};
