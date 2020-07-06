// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1488-avoid-flood-in-the-city/
// https://www.youtube.com/watch?v=8sxeQyumrYc
class Solution {
public:
  vector<int> avoidFlood(vector<int>& rains) {   
    const int n = rains.size();
    vector<int> ans(n, -1);
    unordered_map<int, int> full; // lake -> day
    set<int> dry; // days we can dry lakes.
    for (int i = 0; i < n; ++i) {
      const int lake = rains[i];
      if (lake > 0) {
        if (full.count(lake)) {
          // Find the first day we can dry it.
          auto it = dry.upper_bound(full[lake]);
          if (it == end(dry)) return {};
          ans[*it] = lake;
          dry.erase(it);
        }
        full[lake] = i;
      } else {
        dry.insert(i);
        ans[i] = 1;
      }
    }
    return ans;
  }
};
