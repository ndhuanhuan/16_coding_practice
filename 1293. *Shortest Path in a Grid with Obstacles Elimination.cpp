// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1293-shortest-path-in-a-grid-with-obstacles-elimination/
// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/451787/Python-O(m*n*k)-BFS-Solution-with-Explanation
class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    const vector<int> dirs{0, 1, 0, -1, 0};
    const int n = grid.size();
    const int m = grid[0].size();
    vector<vector<int>> seen(n, vector<int>(m, INT_MAX));
    queue<tuple<int, int, int>> q; 
    int steps = 0;
    q.emplace(0, 0, 0);
    seen[0][0] = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int cx, cy, co;
        tie(cx, cy, co) = q.front(); q.pop();         
        if (cx == m - 1 && cy == n - 1) return steps;
        for (int i = 0; i < 4; ++i) {
          int x = cx + dirs[i];
          int y = cy + dirs[i + 1];
          if (x < 0 || y < 0 || x >= m || y >= n) continue;
          int o = co + grid[y][x];
          if (o >= seen[y][x] || o > k) continue;            
          seen[y][x] = o;
          q.emplace(x, y, o);
        }
      }
      ++steps;
    }
    return -1;
  }
};
