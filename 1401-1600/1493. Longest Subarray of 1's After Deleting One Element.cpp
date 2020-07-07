// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1493-longest-subarray-of-1s-after-deleting-one-element/
class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    int sum = 0; // sum of nums[l~r].
    for (int l = 0, r = 0; r < n; ++r) {
      sum += nums[r];
      // Maintain sum >= r - l, at most 1 zero.
      while (l < r && sum < r - l)
        sum -= nums[l++];
      ans = max(ans, r - l);
    }
    return ans;
  }
};
