// https://zxi.mytechroad.com/blog/string/leetcode-1370-increasing-decreasing-string/
class Solution {
public:
  string sortString(string s) {
    vector<int> count(26);
    for (char c : s) ++count[c - 'a'];
    string ans;
    while (ans.length() != s.length()) {
      for (char c = 'a'; c <= 'z'; ++c)
        if (--count[c - 'a'] >= 0)
          ans += c;
      for (char c = 'z'; c >= 'a'; --c)
        if (--count[c - 'a'] >= 0)
          ans += c;      
    }
    return ans;
  }
};
