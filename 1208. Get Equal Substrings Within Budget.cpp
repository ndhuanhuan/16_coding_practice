// https://zxi.mytechroad.com/blog/sliding-window/leetcode-1208-get-equal-substrings-within-budget/
class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    const int n = s.length();
    int ans = 0;    
    for (int i = 0, j = 0, cost = 0; i < n && j < n; ++i) {
      while (j < n) {
        int c = abs(s[j] - t[j]);
        if (cost + c > maxCost) break;
        cost += c;
        ++j;
      }
      ans = max(ans, j - i);
      cost -= abs(s[i] - t[i]);
    }
    return ans;
  }
};
