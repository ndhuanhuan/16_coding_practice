// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1349-maximum-students-taking-exam/
class Solution {
public:
  int maxStudents(vector<vector<char>>& seats) {
    const int m = seats.size();
    const int n = seats[0].size();
    vector<int> s(m + 1);    
    for (int i = 1; i <= m; ++i)
      for (int j = 0; j < n; ++j)
        s[i] |= (seats[i - 1][j] == '.') << j;
    
    vector<vector<int>> dp(m + 1, vector<int>(1 << n));        
    for (int i = 1; i <= m; ++i)      
      for (int c = s[i];;c = (c - 1) & s[i]) {
        if (c & (c >> 1)) continue;
        for (int l = s[i - 1];;l = (l - 1) & s[i - 1]) {
          if (!(l & (c >> 1)) && !((l >> 1) & c))
            dp[i][c] = max(dp[i][c], dp[i - 1][l] + __builtin_popcount(c));          
          if (l == 0) break;
        }
        if (c == 0) break;
      }
    return *max_element(begin(dp[m]), end(dp[m]));
  }
};
