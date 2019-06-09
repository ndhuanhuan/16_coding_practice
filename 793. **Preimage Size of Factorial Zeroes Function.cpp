//http://zxi.mytechroad.com/blog/math/leetcode-793-preimage-size-of-factorial-zeroes-function/
// https://www.cnblogs.com/grandyang/p/9214055.html

class Solution {
public:
    int preimageSizeFZF(int K) {
        long left = 0, right = 5L * (K + 1);
        while (left < right) {
            long mid = left + (right - left) / 2;
            long cnt = numOfTrailingZeros(mid);
            if (cnt == K) return 5;
            else if (cnt < K) left = mid + 1;
            else right = mid;
        }
        return 0;
    }
    long numOfTrailingZeros(long x) {
        long res = 0;
        for (; x > 0; x /= 5) {
            res += x / 5;
        }
        return res;
    }
};




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
