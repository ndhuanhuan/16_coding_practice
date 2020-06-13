// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1449-form-largest-integer-with-digits-that-add-up-to-target/
class Solution {
public:
  string largestNumber(vector<int>& cost, int target) {    
    // dp[i] = {d, length} of the largest number that costs i. 
    vector<pair<int, int>> dp(target + 1, {-1, -1});
    dp[0] = {0, 0};
    for (int t = 1; t <= target; ++t)
      for (int d = 1; d <= 9; ++d) {
        const int s = t - cost[d - 1];
        if (s < 0 || dp[s].second == -1
            || dp[s].second + 1 < dp[t].second) continue;
        dp[t] = {d, dp[s].second + 1};
      }
    if (dp[target].second == -1) return "0";
    string ans;
    // => use d to calculate next target
    while (target) {
      ans += dp[target].first + '0';
      target -= cost[dp[target].first - 1];
    }
    return ans;
  }
};
