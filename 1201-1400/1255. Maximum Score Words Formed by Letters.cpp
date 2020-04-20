// https://zxi.mytechroad.com/blog/searching/leetcode-1255-maximum-score-words-formed-by-letters/
class Solution {
public:
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<int> counts(26);
    vector<int> scores(words.size());
    for (char c : letters) ++counts[c - 'a'];
    for (int i = 0; i < words.size(); ++i)       
      for (char c : words[i]) scores[i] += score[c - 'a'];
    int ans = 0;
    function<void(int, int)> dfs = [&](int s, int cur) {
      if (cur > ans) ans = cur;
      for (int i = s; i < words.size(); ++i) {
        bool valid = true;
        for (char c : words[i]) valid &= --counts[c - 'a'] >= 0;
        if (valid) dfs(i + 1, cur + scores[i]);
        for (char c : words[i]) ++counts[c - 'a'];        
      }
    };
    dfs(0, 0);
    return ans;
  }
};
