// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1402-reducing-dishes/
class Solution {
public:
  int maxSatisfaction(vector<int>& s) {
    const int n = s.size();
    sort(rbegin(s), rend(s));
    int ans = 0;
    int prefix = 0;
    for (int v : s) {
      prefix += v;
      if (prefix <= 0) break;
      ans += prefix;
    }
    return ans;
  }
};
