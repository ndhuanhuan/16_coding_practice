//https://zxi.mytechroad.com/blog/uncategorized/leetcode-964-least-operators-to-express-number/
class Solution {
public:
  int leastOpsExpressTarget(int x, int target) {
    return dp(x, target);
  }
private:
  unordered_map<int, int> m_;
  int dp(int x, int t) {
    if (t == 0) return 0;
    if (t < x) return min(2 * t - 1, 2 * (x - t));
    if (m_.count(t)) return m_.at(t);
    int k = log(t) / log(x);
    long p = pow(x, k);
    if (t == p) return m_[t] = k - 1;
    int ans = dp(x, t - p) + k; // t - p < t
    long left = p * x - t;
    if (left < t) // only rely on smaller sub-problems
      ans = min(ans, dp(x, left) + k + 1);
    return m_[t] = ans;
  }
};
