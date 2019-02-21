// https://zxi.mytechroad.com/blog/uncategorized/leetcode-921-minimum-add-to-make-parentheses-valid/
class Solution {
public:
  int minAddToMakeValid(string S) {
    int l = 0;    
    int m = 0;
    for (char c : S) {
      if (c == '(') ++l;
      if (c == ')' && l > 0) {
        --l;
        ++m;
      }
    }
    return S.size() - m * 2;
  }
};
