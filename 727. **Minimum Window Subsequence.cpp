// https://leetcode.com/problems/minimum-window-subsequence/discuss/109358/C%2B%2B-DP-with-explanation-O(ST)-53ms
// https://www.cnblogs.com/grandyang/p/8684817.html
// The goal is the substring with length of min(i-dp[i][n-1])
// dp[i][n-1] stores the starting index k, we want to minimize i-k, i is current dp ending index inside S.
// 当 S[i] == T[j] 的时候，实际上起始位置和 dp[i - 1][j - 1] 是一样的，
// 比如 dbd 包含 bd 的起始位置和 db 包含b的起始位置一样，所以可以继承过来。那么当 S[i] != T[j] 的时候，怎么搞？其实是和 dp[i - 1][j] 是一样的，比如 dbd 包含b的起始位置和 db 包含b的起始位置是一样的。
class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
            }
            if (dp[i][n] != -1) {
                int len = i - dp[i][n];
                if (minLen > len) {
                    minLen = len;
                    start = dp[i][n];
                }
            }
        }
        return (start != -1) ? S.substr(start, minLen) : "";
    }
};
