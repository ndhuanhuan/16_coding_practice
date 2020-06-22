// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1437-check-if-all-1s-are-at-least-length-k-places-away/
class Solution {
public:
  bool kLengthApart(vector<int>& nums, int k) {
    int d = k + 1; // distant enough
    for (int n : nums) {
      if (n == 0) {
        ++d;
      } else {
        if (d < k) return false;
        d = 0;
      }
    }
    return true;
  }
};
