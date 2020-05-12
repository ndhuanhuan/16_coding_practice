// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-956-tallest-billboard/
class Solution {
public:
  int tallestBillboard(vector<int>& rods) {    
    const int n = rods.size();
    const int s = accumulate(begin(rods), end(rods), 0);
    // dp[i][j] := min(h1, h2), j = abs(h1 - h2)
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {      
      int h = rods[i - 1];
      for (int j = 0; j <= s - h; ++j) {
        if (dp[i - 1][j] < 0) continue;
        // not used
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);  
        // put on the taller one 
        dp[i][j + h] = max(dp[i][j + h], dp[i - 1][j]); 
        // put on the shorter one
        dp[i][abs(j - h)] = max(dp[i][abs(j - h)], dp[i - 1][j] + min(h, j)); 
      }    
    }
    return dp[n][0];
  }
};
