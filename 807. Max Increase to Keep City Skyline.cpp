// https://zxi.mytechroad.com/blog/greedy/leetcode-807-max-increase-to-keep-city-skyline/
class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> x(n, 0);
    vector<int> y(n, 0);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        x[j] = max(x[j], grid[i][j]);
        y[i] = max(y[i], grid[i][j]);
      }
    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) 
        ans += min(x[i], y[j]) - grid[i][j];
    return ans;
  }
};
