// https://zxi.mytechroad.com/blog/sliding-window/leetcode-1525-number-of-good-ways-to-split-a-string/
class Solution {
public:
  int numSplits(string s) {
    vector<int> r(26);
    vector<int> l(26);
    int cr = 0;
    for (char c : s)
      cr += (++r[c - 'a'] == 1);    
    int ans = 0;
    int cl = 0;
    for (char c : s) {
      cl += (++l[c - 'a'] == 1);
      cr -= (--r[c - 'a'] == 0);
      ans += cl == cr;
    }
    return ans;
  }
};
