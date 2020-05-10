// https://www.cnblogs.com/grandyang/p/11094525.html
class Solution {
public:
    int numPermsDISequence(string S) {
        int res = 0, n = S.size(), M = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (S[i - 1] == 'D') {
                    for (int k = j; k <= i - 1; ++k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
                    } 
                } else {
                    for (int k = 0; k <= j - 1; ++k) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
                    }
                }
            }
        }
        for (int i = 0; i <= n; ++i) {
            res = (res + dp[n][i]) % M;
        }
        return res;
    }
};
