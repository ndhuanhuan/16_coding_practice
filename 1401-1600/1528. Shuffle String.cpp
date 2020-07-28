// https://zxi.mytechroad.com/blog/simulation/1528-shuffle-string/
class Solution {
public:
  string restoreString(string s, vector<int>& indices) {
    string ans(s);
    for (int i = 0; i < indices.size(); ++i)
      ans[indices[i]] = s[i];
    return ans;
  }
};
