// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array/
class Solution {
public:
  int minNumberOperations(vector<int>& target) {
    int ans = target[0];
    for (int i = 1; i < target.size(); ++i)
      ans += max(0, target[i] - target[i - 1]);
    return ans;
  }
};
