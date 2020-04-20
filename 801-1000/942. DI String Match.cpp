//https://zxi.mytechroad.com/blog/greedy/leetcode-942-di-string-match/
class Solution {
public:
  vector<int> diStringMatch(string S) {
    const int n = S.length();
    vector<int> ans;
    int lo = 0;
    int hi = n;
    for (char c : S) {
      if (c == 'I')
        ans.push_back(lo++);
      else
        ans.push_back(hi--);
    }
    ans.push_back(lo);
    return ans;
  }
};
