// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-518-coin-change-2/
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (const int coin : coins)
      for (int i = 0; i <= amount - coin; ++i)
        dp[i + coin] += dp[i];      
    return dp[amount];
  }
};
