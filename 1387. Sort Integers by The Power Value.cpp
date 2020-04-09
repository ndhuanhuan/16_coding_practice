// https://zxi.mytechroad.com/blog/simulation/leetcode-1387-sort-integers-by-the-power-value/
class Solution {
public:
  int getKth(int lo, int hi, int k) {
    vector<pair<int, int>> vals;
    for (int n = lo; n <= hi; ++n) {
      int p = 0;
      int x = n;
      while (x != 1) {
        if (x & 1) x = 3 * x + 1;
        else x /= 2;
        ++p;
      }
      vals.emplace_back(p, n);
    }
    nth_element(begin(vals), begin(vals) + k - 1, end(vals));
    return vals[k - 1].second;
  }
};
