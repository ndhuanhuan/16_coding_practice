// https://zxi.mytechroad.com/blog/bit/leetcode-1318-minimum-flips-to-make-a-or-b-equal-to-c/
class Solution {
public:
  int minFlips(int a, int b, int c) {
    int count = 0;
    for (int i = 0; i < 32; ++i) {      
      if (c & 1) count += 1 - ((a | b) & 1);
      else count += (a & 1) + (b & 1);
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }
    return count;
  }
};
