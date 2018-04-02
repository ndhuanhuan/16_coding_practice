//http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-221-maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> sizes(m, vector<int>(n, 0));
        
        int ans = 0;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                sizes[i][j] = matrix[i][j] - '0';
                if (!sizes[i][j]) continue;                            
                
                if (i == 0 || j == 0) {
                    // do nothing
                } else
                    sizes[i][j] = min(min(sizes[i - 1][j - 1], 
                                          sizes[i - 1][j]),
                                          sizes[i][j - 1]) + 1;
                
                ans = max(ans, sizes[i][j]*sizes[i][j]);
            }
        return ans;
    }
};

//http://www.cnblogs.com/easonliu/p/4548769.html
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size(), res = 0;
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) if (matrix[i][0] == '1') {
            dp[i][0] = 1; res = 1;
        }
        for (int j = 0; j < N; ++j) if (matrix[0][j] == '1') {
            dp[0][j] = 1; res = 1;
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == '1') 
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
