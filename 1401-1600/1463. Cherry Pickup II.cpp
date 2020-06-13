// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1463-cherry-pickup-ii/
class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid) {
    const int r = grid.size();
    const int c = grid[0].size();
    vector<vector<vector<int>>> dp(r + 2, 
      vector<vector<int>>(c + 2, vector<int>(c + 2)));
    for (int y = r; y >= 1; --y)
      for (int x1 = 1; x1 <= c; ++x1)
        for (int x2 = 1; x2 <= c; ++x2) {
          const int cur = grid[y - 1][x1 - 1] + (x1 != x2) * grid[y - 1][x2 - 1];
          int& ans = dp[y][x1][x2];
          for (int d1 = -1; d1 <= 1; ++d1)
            for (int d2 = -1; d2 <= 1; ++d2)
              ans = max(ans, cur + dp[y + 1][x1 + d1][x2 + d2]);          
        }
    return dp[1][1][c];
  }
};
