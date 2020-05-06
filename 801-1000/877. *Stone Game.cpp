// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-877-stone-game/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        // dp[i][j]
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int l =2; l <= n; ++l) {
            for(int i = 0; i <= n-l; ++i) {
                int j = i + l -1;
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] > 0;
    }
};
