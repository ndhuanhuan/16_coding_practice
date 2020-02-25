// https://zxi.mytechroad.com/blog/string/1358-number-of-substrings-containing-all-three-characters/
class Solution {
public:
  int numberOfSubstrings(string s) {
    vector<int> l{-1,-1,-1};
    int ans = 0;
    for (size_t i = 0; i < s.length(); ++i) {
      l[s[i] - 'a'] = i;
      ans += 1 + *min_element(begin(l), end(l));
    }
    return ans;
  }
};
