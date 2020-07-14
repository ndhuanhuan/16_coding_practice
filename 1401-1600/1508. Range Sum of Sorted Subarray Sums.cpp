// https://zxi.mytechroad.com/blog/queue/leetcode-1508-range-sum-of-sorted-subarray-sums/
struct Entry {
  int sum;
  int i;
  bool operator<(const Entry& e) const { return sum > e.sum; }
};
 
class Solution {
public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    constexpr int kMod = 1e9 + 7;
    priority_queue<Entry> q; // Sort by e.sum in descending order.
    for (int i = 0; i < n; ++i)
      q.push({nums[i], i});
    long ans = 0;
    for (int j = 1; j <= right; ++j) {
      const auto e = std::move(q.top()); q.pop();
      if (j >= left) ans += e.sum;
      if (e.i + 1 < n) q.push({e.sum + nums[e.i + 1], e.i + 1});
    }
    return ans % kMod;
  }
};
