// https://zxi.mytechroad.com/blog/greedy/leetcode-1326-minimum-number-of-taps-to-open-to-water-a-garden/
class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
    vector<pair<int, int>> t;
    // O(n) reduction
    for (int i = 0; i <= n; ++i)
      t.emplace_back(max(0, i - ranges[i]), 
                     min(i + ranges[i], n));
    
    // 1024. Video Stiching
    sort(begin(t), end(t));
    int ans = 0;
    int i = 0;
    int l = 0;
    int e = 0;
    while (e < n) {
      // Extend to the right most w.r.t t[i].first <= l
      while (i <= n && t[i].first <= l)
        e = max(e, t[i++].second);
      if (l == e) return -1; // Can not extend
      l = e;
      ++ans;
    }
    return ans;
  }
};
