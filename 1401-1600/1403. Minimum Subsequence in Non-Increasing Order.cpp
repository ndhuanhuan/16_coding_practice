// https://zxi.mytechroad.com/blog/greedy/leetcode-1403-minimum-subsequence-in-non-increasing-order/
class Solution {
public:
  vector<int> minSubsequence(vector<int>& nums) {
    sort(rbegin(nums), rend(nums));
    int total = accumulate(begin(nums), end(nums), 0);
    vector<int> ans;
    int sum = 0;
    for (int v : nums) {
      sum += v;
      ans.push_back(v);
      if (sum > total / 2) break;
    }
    return ans;
  }
};
