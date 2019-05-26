// https://zxi.mytechroad.com/blog/string/leetcode-806-number-of-lines-to-write-string/
class Solution {
public:
  vector<int> numberOfLines(vector<int>& widths, string S) {
    int lines = 1;
    int units = 0;
    for (char c : S) {
      if (units + widths[c - 'a'] > 100) {
        ++lines;
        units = 0;
      }
      units += widths[c - 'a'];
    }
    return {lines, units};
  }
};
