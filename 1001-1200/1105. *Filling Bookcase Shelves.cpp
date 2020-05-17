// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1105-filling-bookcase-shelves/
class Solution {
public:
  int minHeightShelves(vector<vector<int>>& books, int sw) {
    int n = books.size();      
    vector<int> dp(n, INT_MAX / 2);
    for (int i = 0; i < n; ++i) {
      int w = 0;
      int h = 0;
      for (int j = i; j < n; ++j) {        // tricky; reverse interation, since we don't want to use already overriden value in line 13
        if ((w += books[j][0]) > sw) break;
        h = max(h, books[j][1]);
        dp[j] = min(dp[j], (i == 0 ? 0 : dp[i - 1]) + h);
      }
    }
    return dp.back();
  }
};
