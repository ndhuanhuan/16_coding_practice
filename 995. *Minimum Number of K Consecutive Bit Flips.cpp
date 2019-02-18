
// https://zxi.mytechroad.com/blog/greedy/leetcode-995-minimum-number-of-k-consecutive-bit-flips/
class Solution {
public:
  int minKBitFlips(vector<int>& A, int K) {
    int ans = 0;    
    for (int i = 0; i <= A.size() - K; ++i) {
      if (A[i] == 1) continue;
      ++ans;
      for (int j = 0; j < K; ++j)
        A[i + j] ^= 1;      
    }
    for (int i = A.size() - K + 1; i < A.size(); ++i)
      if (A[i] == 0) return -1;
    return ans;
  }
};
