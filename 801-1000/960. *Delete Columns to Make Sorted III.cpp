// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-960-delete-columns-to-make-sorted-iii/
class Solution {
public:
  int minDeletionSize(vector<string>& A) {
    vector<int> dp(A[0].length(), 1);
    for (int i = 0; i < A[0].length(); ++i)
      for (int j = 0; j < i; ++j) {
        bool valid = true;
        for (const auto& a : A)
          if (a[j] > a[i]) {
            valid = false;
            break;
          }
        if (valid) dp[i] = max(dp[i], dp[j] + 1);
      }
    return A[0].length() - *max_element(begin(dp), end(dp));
  }
};
