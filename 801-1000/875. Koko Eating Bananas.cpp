// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-875-koko-eating-bananas/
class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int H) {
    int l = 1;
    int r = *max_element(begin(piles), end(piles)) + 1;
    while (l < r) {
      int m = (r - l) / 2 + l;
      int h = 0;
      for (int p : piles)
        h += (p + m - 1) / m;
      if (h <= H)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
