// https://zxi.mytechroad.com/blog/uncategorized/leetcode-964-least-operators-to-express-number/
class Solution {
public:
  int leastOpsExpressTarget(int x, int target) {
    set<pair<int, int>> q; // # x -> number
    unordered_set<int> s;
    q.emplace(0, target);
    while (!q.empty()) {
      const auto it = begin(q);
      const int c = it->first;
      const int t = it->second;
      q.erase(it);
      if (t == 0) return c - 1;
      if (s.count(t)) continue;
      s.insert(t);      
      int n = log(t) / log(x);
      int l = t - pow(x, n);
      q.emplace(c + (n == 0 ? 2 : n), l);
      int r = pow(x, n + 1) - t;
      q.emplace(c + n + 1, r);
    }
    return -1;
  }
};
