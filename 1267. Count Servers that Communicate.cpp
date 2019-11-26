// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1267-count-servers-that-communicate/
class Solution {
public:
  int countServers(vector<vector<int>>& grid) {
    const size_t m = grid.size();
    const size_t n = grid[0].size();
    vector<int> rows(m);
    vector<int> cols(n);
    for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j) {
        rows[i] += grid[i][j];
        cols[j] += grid[i][j];
      }
    int ans = 0;
     for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j)
        ans += (rows[i] > 1 || cols[j] > 1) ? grid[i][j] : 0;
    return ans;
  }
};
