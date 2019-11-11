// https://zxi.mytechroad.com/blog/searching/leetcode-1254-number-of-closed-islands/
// Author: Huahua
class Solution {
public:
  int closedIsland(vector<vector<int>>& grid) {    
    const int n = grid.size();
    const int m = grid[0].size();    
    function<int(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || y < 0 || x >= m || y >= n) return 0;      
      if (grid[y][x]++) return 1;  // early stopping
      return dfs(x + 1, y) & dfs(x - 1, y) & dfs(x, y + 1) & dfs(x, y - 1);
    };
    
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (!grid[i][j]) ans += dfs(j, i);      // only scan 0
    return ans;
  }
};
