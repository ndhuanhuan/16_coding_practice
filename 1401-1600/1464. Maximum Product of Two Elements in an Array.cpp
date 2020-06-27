// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1464-maximum-product-of-two-elements-in-an-array/
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int m1 = 0;
    int m2 = 0;
    for (int n : nums) {
      if (n > m1) {
        m2 = m1;
        m1 = n;
      } else if (n > m2) {
        m2 = n;
      }
    }
    return (m1 - 1) * (m2 - 1);
  }
};
