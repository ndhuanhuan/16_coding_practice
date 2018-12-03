//https://zxi.mytechroad.com/blog/greedy/leetcode-945-minimum-increment-to-make-array-unique/
class Solution {
public:
  int minIncrementForUnique(vector<int>& A) {
    int ans = 0;
    sort(begin(A), end(A));
    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1]) continue;
      ans += (A[i - 1] - A[i]) + 1;
      A[i] = A[i] + 1;
    }
    return ans;
  }
};
