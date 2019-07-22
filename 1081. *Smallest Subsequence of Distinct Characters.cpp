// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/discuss/308194/C%2B%2B-O(n)-identical-to-316

class Solution {
public:
    string smallestSubsequence(string s, string res = "") {
      int cnt[26] = {}, used[26] = {};
      for (auto ch : s) ++cnt[ch - 'a'];
      for (auto ch : s) {
        --cnt[ch - 'a'];
        if (used[ch - 'a']++ > 0) continue;
        while (!res.empty() && res.back() > ch && cnt[res.back() - 'a'] > 0) {
          used[res.back() - 'a'] = 0;
          res.pop_back();
        }
        res.push_back(ch);
      }
      return res;
    }  
};
