// https://leetcode.com/problems/two-sum-less-than-k/discuss/326486/C%2B%2B-3-solutions
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K, int S = -1) {
      sort(begin(A), end(A));
      for (int i = 0, j = A.size() - 1; i < j; ) {
        if (A[i] + A[j] < K) S = max(S, A[i++] + A[j]);
        else --j;
      }
      return S;
    }
};
