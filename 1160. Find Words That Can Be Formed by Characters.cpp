
class Solution {
public:
    int countCharacters(vector<string>& words, string chars, int res = 0) {
      vector<int> cnt(26);
      for (auto ch : chars) ++cnt[ch - 'a'];
      for (auto w : words) {
        vector<int> cnt1 = cnt;
        bool match = true;
        for (auto ch : w) {
          if (--cnt1[ch - 'a'] < 0) {
            match = false;
            break;
          }
        }
        if (match) res += w.size();
      }
      return res;
    }
};
