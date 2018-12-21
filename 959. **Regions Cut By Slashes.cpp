//https://zxi.mytechroad.com/blog/graph/leetcode-959-regions-cut-by-slashes/
class Solution {
public:
  int regionsBySlashes(vector<string>& grid) {
    const int n = grid.size();
    vector<vector<int>> g(n * 3, vector<int>(n * 3));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '/') {
          g[i * 3 + 0][j * 3 + 2] = 1;
          g[i * 3 + 1][j * 3 + 1] = 1;
          g[i * 3 + 2][j * 3 + 0] = 1;
        } else if (grid[i][j] == '\\') {
          g[i * 3 + 0][j * 3 + 0] = 1;
          g[i * 3 + 1][j * 3 + 1] = 1;
          g[i * 3 + 2][j * 3 + 2] = 1;
        }
      }
    int ans = 0;
    for (int i = 0; i < 3 * n; ++i)
      for (int j = 0; j < 3 * n; ++j) {
        if (g[i][j]) continue;
        visit(g, j, i, n * 3);
        ++ans;
      }
    return ans;
  }
private:
  void visit(vector<vector<int>>& g, int x, int y, int n) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (g[y][x]) return;
    g[y][x] = 1;
    visit(g, x + 1, y, n);
    visit(g, x, y + 1, n);
    visit(g, x - 1, y, n);
    visit(g, x, y - 1, n);
  }
};
