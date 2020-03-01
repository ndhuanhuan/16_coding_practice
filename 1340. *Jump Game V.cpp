// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1344-jump-game-v/
class Solution {
public:
  int maxJumps(vector<int>& a, int d) {
    const int n = a.size();
    vector<pair<int, int>> m(n); // <height, index>
    for (int i = 0; i < n; ++i)
      m[i] = {a[i], i};    
    // Solve from the lowest bar.
    sort(begin(m), end(m));    
 
    vector<int> dp(n, 1);
    for (auto [v, i] : m) {      
      for (int j = i + 1; j <= min(n - 1, i + d) && a[i] > a[j]; ++j) 
        dp[i] = max(dp[i], dp[j] + 1);
      for (int j = i - 1; j >= max(0, i - d) && a[i] > a[j]; --j)
        dp[i] = max(dp[i], dp[j] + 1);
    }
    
    return *max_element(begin(dp), end(dp));
  }
};
