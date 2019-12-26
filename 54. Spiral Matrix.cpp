
// https://zxi.mytechroad.com/blog/simulation/leetcode-54-spiral-matrix/
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    int l = 0;
    int t = 0;
    int r = matrix[0].size();
    int b = matrix.size();
    const int total = (r--) * (b--);      
    int d = 0;
    int x = 0;
    int y = 0;
    vector<int> ans;
    while (ans.size() < total - 1) {      
      if (d == 0) {
        while (x < r) ans.push_back(matrix[y][x++]);
        ++t; //top
      } else if (d == 1) {
        while (y < b) ans.push_back(matrix[y++][x]);
        --r; // right
      } else if (d == 2) {
        while (x > l) ans.push_back(matrix[y][x--]);
        --b; // bottom
      } else if (d == 3) {
        while (y > t) ans.push_back(matrix[y--][x]);
        ++l; // left
      }
      d = (d + 1) % 4;
    }
    if (ans.size() != total) ans.push_back(matrix[y][x]);
    return ans;
  }
};
