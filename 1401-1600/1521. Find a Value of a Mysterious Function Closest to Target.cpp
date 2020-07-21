// https://zxi.mytechroad.com/blog/bit/leetcode-1521-find-a-value-of-a-mysterious-function-closest-to-target/
class Solution {
public:
  int closestToTarget(vector<int>& arr, int target) {
    const int n = arr.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int s = arr[i];
      for (int j = i; j < n; ++j) {
        s &= arr[j];
        ans = min(ans, abs(s - target));
        if (ans == 0) return 0;
        if (s <= target) break; // s is decreasing.
      }
      if (s > target) break; // s is increasing.
    }
    return ans;
  }
};
