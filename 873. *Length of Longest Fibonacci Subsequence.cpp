// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-873-length-of-longest-fibonacci-subsequence/
// dp[a, b] represents the length of fibo sequence ends up with (a, b)
// Then we have dp[a, b] = (dp[b - a, a] + 1 ) or 2

//Tricky: dp(a, b) rely on dp(b-a, a). dp(b-a, a) means longest start from (b-a) to a which is a valid pre sequence for dp(a, b)
// We need to iterate both a, b 
class Solution {
public:
  int lenLongestFibSubseq(vector<int>& A) {
    const int n = A.size();        
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
      m[A[i]] = i;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int ans = 0;
    for (int j = 0; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        int a_i = A[k] - A[j];
        if (a_i >= A[j]) break; // pruning 168 ms -> 68 ms
        auto it = m.find(a_i);
        if (it == end(m)) continue;
        int i = it->second;
        dp[j][k] = dp[i][j] + 1;        
        ans = max(ans, dp[j][k]);
      }
    return ans;
  }
};
