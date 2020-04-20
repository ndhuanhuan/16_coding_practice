// https://www.cnblogs.com/grandyang/p/6188893.html
// 0 -1 knapsack problem, classic => https://www.kancloud.cn/kancloud/pack/70125

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // for 1...N
        for(auto str: strs) {
            int zeros = 0, ones = 0;
            for(char c: str) {
                if(c == '1') {
                    ++ones;
                } else {
                    ++zeros;
                }
            }
            
            // For V...0
            for(int i = m; i >= zeros; --i) {
                for(int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        
        
        
        return dp[m][n];
    }
};
