// https://zxi.mytechroad.com/blog/math/leetcode-908-smallest-range-i/
class Solution {
public:
  int smallestRangeI(vector<int>& A, int K) {
    int a_min = *min_element(begin(A), end(A));
    int a_max = *max_element(begin(A), end(A));
    return max(0, (a_max - a_min) - 2 * K);
  }
};
