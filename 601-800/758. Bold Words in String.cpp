// https://zxi.mytechroad.com/blog/string/leetcode-758-bold-words-in-string/
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
      const int kMaxWordLen = 10;      
      unordered_set<string> dict(words.begin(), words.end());
      
      int n = S.length();
      vector<int> bolded(n, 0);
      for (int i = 0; i < n; ++i)
        for (int l = 1; l <= min(n - i, kMaxWordLen); ++l)
          if (dict.count(S.substr(i, l)))
            std::fill(bolded.begin() + i, bolded.begin() + i + l, 1);
      
      string ans;
      for (int i = 0; i < n; ++i) {
        if (bolded[i] && (i == 0 || !bolded[i - 1])) ans += "<b>";
        ans += S[i];
        if (bolded[i] && (i == n - 1 || !bolded[i + 1])) ans += "</b>";
      }
      
      return ans;
    }
};
