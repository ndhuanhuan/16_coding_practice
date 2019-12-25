// https://zxi.mytechroad.com/blog/math/leetcode-463-island-perimeter/
class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int area = 0;
    int conn = 0;
 
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
        if (grid[y][x] == 1) {
          ++area;
          if (y > 0 && grid[y - 1][x] == 1) ++conn;
          if (x > 0 && grid[y][x - 1] == 1) ++conn;
        }
 
    return area*4 - conn*2;
  }
};
