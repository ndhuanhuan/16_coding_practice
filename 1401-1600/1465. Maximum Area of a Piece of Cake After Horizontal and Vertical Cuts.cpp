// https://zxi.mytechroad.com/blog/geometry/leetcode-1465-maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    constexpr int kMod = 1e9 + 7;
    sort(begin(verticalCuts), end(verticalCuts));
    sort(begin(horizontalCuts), end(horizontalCuts));
    int mx = max(verticalCuts[0], w - verticalCuts.back());
    int my = max(horizontalCuts[0], h - horizontalCuts.back());
    for (int i = 1; i < verticalCuts.size(); ++i)
      mx = max(mx, verticalCuts[i] - verticalCuts[i - 1]);
    for (int i = 1; i < horizontalCuts.size(); ++i)
      my = max(my, horizontalCuts[i] - horizontalCuts[i - 1]);               
    return static_cast<long>(mx) * my % kMod;
  }
};
