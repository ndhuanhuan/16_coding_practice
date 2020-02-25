// https://zxi.mytechroad.com/blog/string/1358-number-of-substrings-containing-all-three-characters/
// "abcabc"
// when i = 3, 1 + min_element({0,1,2}) => 1, which is "abc"
// when i = 4, 1 + min_element({3,1,2}) => 2, which is "abca", "bca"
// ...
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
