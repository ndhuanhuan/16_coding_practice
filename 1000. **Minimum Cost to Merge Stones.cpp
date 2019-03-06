// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1000-minimum-cost-to-merge-stones/
class Solution {
public:
  int mergeStones(vector<int>& stones, int K) {
    const int n = stones.size();
    if ((n - 1) % (K - 1)) return -1;
    const int kInf = 1e9;    
    vector<int> sums(n + 1);
    for (int i = 0; i < stones.size(); ++i)
      sums[i + 1] = sums[i] + stones[i];
    // dp[l][i] := min cost to merge subarray A[i:i+l] as less piles as possible.
    vector<vector<int>> dp(n + 1, vector<int>(n, kInf));
    for (int l = 1; l < K; ++l)
      fill(begin(dp[l]), end(dp[l]), 0);
    for (int l = K; l <= n; ++l) // subproblem length 
      for (int i = 0; i <= n - l; ++i) { // start        
        for (int m = 1; m < l ; m += K - 1) // left part length
            dp[l][i] = min(dp[l][i], dp[m][i] + dp[l - m][i + m]);
        // If the current length can be merged into 1 pile
        // The cost is independent of the merge orders.
        if ((l - 1) % (K - 1) == 0)
          dp[l][i] += sums[i + l] - sums[i];
      }
    return dp[n][0];
  }
};
