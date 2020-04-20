// https://zxi.mytechroad.com/blog/greedy/leetcode-1147-longest-chunked-palindrome-decomposition/
class Solution {
public:
  int longestDecomposition(string_view text) {    
    const int n = text.length();
    if (n == 0) return 0;
    for (int l = 1; l <= n / 2; ++l) {
      if (text.substr(0, l) == text.substr(n - l)) 
        return 2 + longestDecomposition(text.substr(l, n - 2 * l));
    }
    return 1;
  }
};
