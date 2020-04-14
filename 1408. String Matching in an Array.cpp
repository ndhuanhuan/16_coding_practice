// https://zxi.mytechroad.com/blog/string/leetcode-1408-string-matching-in-an-array/
class Solution {
public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    const int n = words.size();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (words[j].find(words[i]) != string::npos) {
          ans.push_back(words[i]);
          break;
        }
      }
    return ans;
  }
};
