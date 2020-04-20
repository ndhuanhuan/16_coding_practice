// https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/discuss/377323/C%2B%2B-O(n)-two-pointers
class Solution {
public:
    int countLetters(string S, int res = 0) {
      for (auto i = 1, j = 0; i <= S.size(); ++i) {
        if (i == S.size() || S[i] != S[j]) {
            res += (i - j + 1) * (i - j) / 2;
            j = i;
        } 
      }
      return res;
    }
};
