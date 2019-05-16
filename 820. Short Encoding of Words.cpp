// https://zxi.mytechroad.com/blog/string/leetcode-820-short-encoding-of-words/
class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string> s(words.begin(), words.end());
    for (const string& w : words) {
      for (int i = w.length() - 1; i > 0; --i)        
        s.erase(w.substr(i));
    }
    int ans = 0;
    for (const string& w : s)
      ans += w.length() + 1;
    return ans;
  }
};
