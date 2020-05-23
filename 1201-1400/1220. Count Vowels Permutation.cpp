// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1220-count-vowels-permutation/
class Solution {
public:
  int countVowelPermutation(int n) {
    constexpr int kMod = 1e9 + 7;
    long a = 1, e = 1, i = 1, o = 1, u = 1;
    
    for (int k = 2; k <= n; ++k) {
      long aa = (i + e + u) % kMod;
      long ee = (i + a) % kMod;
      long ii = (e + o) % kMod;
      long oo = i % kMod;
      long uu = (i + o) % kMod;
      a = aa;
      e = ee;
      i = ii;
      o = oo;
      u = uu;
    }
    return (a + e + i + o + u) % kMod;
  }
};
