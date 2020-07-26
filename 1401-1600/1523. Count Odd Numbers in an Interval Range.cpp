// https://zxi.mytechroad.com/blog/math/leetcode-1523-count-odd-numbers-in-an-interval-range/
class Solution {
public:
  int countOdds(int low, int high) {
    return (high + 1) / 2 - low / 2;
  }
};
