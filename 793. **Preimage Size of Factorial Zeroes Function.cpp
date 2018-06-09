//http://zxi.mytechroad.com/blog/math/leetcode-793-preimage-size-of-factorial-zeroes-function/
class Solution {
public:
  int preimageSizeFZF(int K) {
    return g(K) - g(K - 1);
  }
private:
  // Find the largest number l, that numZeros(l!) == K and numZeros((l+1)!) > K
  int g(int K) {    
    int l = 0;
    int r = INT_MAX;
    while (l < r) {
      int m = l + (r - l) / 2;
      int zeros = numZeros(m);
      if (zeros <= K)
        l = m + 1;
      else
        r = m;
    }    
    return l;
  }
  
  int numZeros(int n) {
    return n < 5 ? 0 : n / 5 + numZeros(n / 5);
  }
};
