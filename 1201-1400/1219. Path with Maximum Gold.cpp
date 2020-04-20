// https://zxi.mytechroad.com/blog/searching/leetcode-1219-path-with-maximum-gold/
class Solution {
public:
  int getMaximumGold(vector<vector<int>>& g) {
    int n = g.size();
    int m = g[0].size();
    int ans = 0;
    function<int(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || x >= m || y < 0 || y >= n || g[y][x] == 0) return 0;
      int c = 0;
      swap(c, g[y][x]); // trick: don't let it revist current value
      int r = c + max({dfs(x - 1, y), dfs(x + 1, y), dfs(x, y - 1), dfs(x, y + 1)});
      swap(c, g[y][x]);
      return r;
    };
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < m; ++j)        
        ans = max(ans, dfs(j, i));
    return ans;
  }
};
