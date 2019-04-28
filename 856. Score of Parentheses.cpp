// https://zxi.mytechroad.com/blog/string/leetcode-856-score-of-parentheses/
class Solution {
public:
  int scoreOfParentheses(string S) {
    return score(S, 0, S.length() - 1);
  }
private:
  int score(const string& S, int l, int r) {    
    if (r - l == 1) return 1; // "()"
    int b = 0;
    for (int i = l; i < r; ++i) {
      if (S[i] == '(') ++b;
      if (S[i] == ')') --b;
      if (b == 0) // balanced
        // score("(A)(B)") = score("(A)") + score("(B)")
        return score(S, l, i) + score(S, i + 1, r);    
    }
    // score("(A)") = 2 * score("A")
    return 2 * score(S, l + 1, r - 1); 
  }
};
