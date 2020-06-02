// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1344-jump-game-v/
class Solution {
public:
  int maxJumps(vector<int>& a, int d) {
    int n = a.size();    
    vector<int> m(n);
    function<int(int)> dp = [&](int i) {
      if (m[i]) return m[i];
      int ans = 1;
      for (int j = i + 1; j <= min(n - 1, i + d) && a[i] > a[j]; ++j) 
        ans = max(ans, dp(j) + 1);
      for (int j = i - 1; j >= max(0, i - d) && a[i] > a[j]; --j)
        ans = max(ans, dp(j) + 1);        
      return m[i] = ans;
    };
    
    int ans = 0;
    for (int i = 0; i < n; ++i)  
      ans = max(ans, dp(i));    
    return ans;
  }
};
