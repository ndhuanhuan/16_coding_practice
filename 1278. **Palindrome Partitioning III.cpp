// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1278-palindrome-partitioning-iii/
class Solution {
public:
  int palindromePartition(string s, int K) {
    const int n = s.length();
    auto minChange = [&](int i, int j) {
      int c = 0;
      while (i < j) 
        if (s[i++] != s[j--]) ++c;      
      return c;
    };
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        cost[i][j] = minChange(i, j);
 
    // dp[i][j] := min changes to make s[0~i] into k palindromes
    vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX / 2));
    for (int i = 0; i < n; ++i) {      
      dp[i][1] = cost[0][i];
      for (int k = 1; k <= K; ++k)
        for (int j = 0; j < i; ++j)
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + cost[j + 1][i]);        
    }
    return dp[n - 1][K];
  }
};
