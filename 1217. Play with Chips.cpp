// https://leetcode.com/problems/play-with-chips/discuss/398239/C%2B%2B-3-lines
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
      int cnt[2] = {};
      for (auto p : chips) ++cnt[p % 2];
      return min(cnt[0], cnt[1]);
    }
};
