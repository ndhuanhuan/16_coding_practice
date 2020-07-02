// https://zxi.mytechroad.com/blog/simulation/leetcode-1470-shuffle-the-array/
class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(n * 2);
    for (int i = 0; i < 2 * n; ++i)
      ans[i] = nums[i / 2 + n * (i % 2)];
    return ans;
  }
};
