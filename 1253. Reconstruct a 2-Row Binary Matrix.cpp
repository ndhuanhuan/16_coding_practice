// https://zxi.mytechroad.com/blog/greedy/leetcode-1253-reconstruct-a-2-row-binary-matrix/
class Solution {
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    const int n = colsum.size();
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < n; ++i)
      if (colsum[i] == 2) {
        a[0][i] = a[1][i] = 1;
        --upper;
        --lower;
      }
    
    for (int i = 0; i < n; ++i)
      if (colsum[i] == 1)
        if (upper > lower) {
          a[0][i] = 1;
          --upper;
        } else {
          a[1][i] = 1;
          --lower;
        }
    if (upper != 0 || lower != 0) return {};
    return a;
  }
};
