// https://leetcode.com/problems/shortest-way-to-form-string/discuss/309404/C%2B%2B-with-picture-greedy
// find a better solution?
class Solution {
public:
    int shortestWay(string s, string t) {
      auto i = 0, j = 0, res = 0;
      while (i < t.size() && res <= i) {
        while (t[i] != s[j] && j < s.size()) ++j;
        if (j == s.size()) j = 0, ++res;
        else ++i, ++j;
      }
      return res <= i ? res + 1 : -1;
    }
};
