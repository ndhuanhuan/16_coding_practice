//http://www.cnblogs.com/grandyang/p/5148030.html
class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int> > &matrix, vector<vector<int> > &dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        vector<vector<int> > dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int mx = 1, m = matrix.size(), n = matrix[0].size();
        for (auto a : dirs) {
            int x = i + a[0], y = j + a[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + dfs(matrix, dp, x, y);
            mx = max(mx, len);
        }
        dp[i][j] = mx;
        return mx;
    }
};

// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-329-longest-increasing-path-in-a-matrix/
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    m_ = matrix.size();
    n_ = matrix[0].size();
    dp_ = vector<vector<int>>(m_, vector<int>(n_, -1)); 
    int ans = 0;
    for (int y = 0; y < m_; ++y)
      for (int x = 0; x < n_; ++x)
        ans = max(ans, dfs(matrix, x, y));
    return ans;
  }
private:
  int dfs(const vector<vector<int>>& mat, int x, int y) {
    if (dp_[y][x] != -1) return dp_[y][x];
    static int dirs[] = {0, -1, 0, 1, 0};
    dp_[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
      int tx = x + dirs[i];
      int ty = y + dirs[i + 1];
      if (tx < 0 || ty < 0 || tx >= n_ || ty >= m_ || mat[ty][tx] <= mat[y][x]) 
        continue;
      dp_[y][x] = max(dp_[y][x], 1 + dfs(mat, tx, ty));
    }
    return dp_[y][x];
  }
  
  int m_;
  int n_;
  // dp[i][j]: max length start from (j, i)
  vector<vector<int>> dp_;  
};
