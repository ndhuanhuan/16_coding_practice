// https://zxi.mytechroad.com/blog/simulation/leetcode-889-spiral-matrix-iii/
class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> ans;
    int k = 0;
    int dirs[][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // ESWN
    int d = 0; // E
    ans.push_back({r0, c0});
    if (ans.size() == R * C) return ans;
    while (++k) {
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < k; ++j) {
          c0 += dirs[d][0];
          r0 += dirs[d][1];          
          if (c0 < 0 || c0 >= C || r0 < 0 || r0 >= R) continue;
          ans.push_back({r0, c0});
          if (ans.size() == R * C) return ans;
        }
      d = (d + 1) % 4;
      }
    }
    return {};
  }
};
