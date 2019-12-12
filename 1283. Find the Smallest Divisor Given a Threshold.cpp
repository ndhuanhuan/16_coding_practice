// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1283-find-the-smallest-divisor-given-a-threshold/
class Solution {
public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    auto sums = [&](int d) {
      int s = 0;
      for (int n : nums)
        s += (n + (d - 1)) / d;
      return s;
    };
    int l = 1;
    int r = 1e6;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (sums(m) <= threshold)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
