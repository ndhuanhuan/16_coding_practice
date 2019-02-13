//https://zxi.mytechroad.com/blog/two-pointers/leetcode-992-subarrays-with-k-different-integers/
class Solution {
public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    // Returns the number of subarrays with k or less distinct numbers.
    auto subarrys = [&A](int k) {
      vector<int> count(A.size() + 1);
      int ans = 0;
      int i = 0;
      for (int j = 0; j < A.size(); ++j) {
        if (count[A[j]]++ == 0) 
          --k;
        while (k < 0)
          if (--count[A[i++]] == 0) ++k;
        ans += j - i + 1;
      }
      return ans;
    };
    return subarrys(K) - subarrys(K - 1);
  }
};
