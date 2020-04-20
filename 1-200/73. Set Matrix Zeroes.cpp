// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-73-set-matrix-zeroes/
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> rows(m);
    vector<int> cols(n);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        rows[i] |= (matrix[i][j] == 0);
        cols[j] |= (matrix[i][j] == 0);
      }
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (rows[i] || cols[j]) matrix[i][j] = 0;        
  }
};
