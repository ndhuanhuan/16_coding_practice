// https://zxi.mytechroad.com/blog/searching/leetcode-994-rotting-oranges/
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) ++fresh;
        else if (grid[i][j] == 2) q.emplace(j, i);
    vector<int> dirs = {1, 0, -1, 0, 1};    
    int days = 0;
    while (!q.empty() && fresh) {
      int size = q.size();
      while (size--) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int dx = x + dirs[i];
          int dy = y + dirs[i + 1];
          if (dx < 0 || dx >= n || dy < 0 || dy >= m || grid[dy][dx] != 1) continue;
          --fresh;
          grid[dy][dx] = 2;
          q.emplace(dx, dy);
        }
      }
      ++days;
    }    
    return fresh ? -1 : days;
  }
};
