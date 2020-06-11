// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1425-constrained-subset-sum/
class Solution {
public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> dp(n);
    deque<int> q;
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > k && q.front() == i - k - 1)
        q.pop_front();
      dp[i] = (q.empty() ? 0 : max(dp[q.front()], 0))
             + nums[i];
      while (!q.empty() && dp[i] >= dp[q.back()])
        q.pop_back();
      q.push_back(i);
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
