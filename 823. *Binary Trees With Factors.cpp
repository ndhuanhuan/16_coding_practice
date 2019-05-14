// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-823-binary-trees-with-factors/
class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& A) {
    constexpr long kMod = 1000000007;
    std::sort(A.begin(), A.end());
    unordered_map<int, long> dp;
    for (int i = 0; i < A.size(); ++i) {
      dp[A[i]] = 1;
      for (int j = 0; j < i; ++j)
        if (A[i] % A[j] == 0 && dp.count(A[i] / A[j]))
          dp[A[i]] += (dp[A[j]] * dp[A[i] / A[j]]) % kMod;
    }    
    long ans = 0;
    for (const auto& kv : dp)
      ans += kv.second;
    return ans % kMod;
  }
};
