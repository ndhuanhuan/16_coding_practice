// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1411-number-of-ways-to-paint-n-x-3-grid/
class Solution {
public:
    int numOfWays(int n) {
        constexpr int kMod = 1e9 + 7;
        vector<vector<long>> dp(n+1, vector<long>(2,0));
        dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 6;
        
        for(int i = 2; i <= n; ++i) {
            dp[i][0] = (dp[i-1][0] * 3 + dp[i-1][1] * 2) % kMod;
            dp[i][1] = (dp[i-1][0] * 2 + dp[i-1][1] * 2) % kMod;
        }
        
        return (dp[n][0] + dp[n][1]) % kMod;
    }
};
