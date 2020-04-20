// https://zxi.mytechroad.com/blog/math/leetcode-1332-remove-palindromic-subsequences/
class Solution {
public:
  int removePalindromeSub(string s) {
    if (s.empty()) return 0;
    if (s == string(rbegin(s), rend(s))) return 1;
    return 2;
  }
};
