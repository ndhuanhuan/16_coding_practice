
class Solution {
public:
  int projectionArea(vector<vector<int>>& grid) {
    int n = grid.size();    
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int h = 0;
      for (int j = 0; j < m; ++j) {
        h = max(h, grid[i][j]);
        if (grid[i][j] != 0) ++ans;
      }
      ans += h;      
    }
    for (int j = 0; j < m; ++j) {
      int h = 0;
      for (int i = 0; i < n; ++i)
        h = max(h, grid[i][j]);
      ans += h;      
    }
    return ans;
  }
};
