// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1301-number-of-paths-with-max-score/
class Solution {
public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    constexpr int kMod = 1e9 + 7;
    const int n = board.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<vector<int>> cc(n + 1, vector<int>(n + 1, 0));
    board[n - 1][n - 1] = board[0][0] = '0';
    cc[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        if (board[i][j] != 'X') {          
          int m = max({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
          dp[i][j] = (board[i][j] - '0') + m;
          if (dp[i + 1][j] == m) 
            cc[i][j] = (cc[i][j] + cc[i + 1][j]) % kMod;
          if (dp[i][j + 1] == m)
            cc[i][j] = (cc[i][j] + cc[i][j + 1]) % kMod;
          if (dp[i + 1][j + 1] == m)
            cc[i][j] = (cc[i][j] + cc[i + 1][j + 1]) % kMod;
        }
      }
    return {cc[0][0] ? dp[0][0] : 0, cc[0][0]};
  }
};
