// https://leetcode.com/problems/check-if-it-is-a-good-array/discuss/419368/JavaC%2B%2BPython-Chinese-Remainder-Theorem
// https://zxi.mytechroad.com/blog/math/leetcode-1250-check-if-it-is-a-good-array/
// https://www.youtube.com/watch?v=WGO4Tqx5owg
class Solution {
public:
  bool isGoodArray(vector<int>& nums) {
    int g = nums[0];
    for (int x : nums)
      g = gcd(g, x);    
    return g == 1;
  }
};
