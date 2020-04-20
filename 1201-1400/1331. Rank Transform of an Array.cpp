// https://zxi.mytechroad.com/blog/hashtable/leetcode-1331-rank-transform-of-an-array/
class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    set<int> s(begin(arr), end(arr)); // sort
    unordered_map<int, int> m;
    int r = 0;
    for (const int v : s) m[v] = ++r;
    vector<int> ans(arr.size());
    for (int i = 0; i < arr.size(); ++i)
      ans[i] = m[arr[i]];
    return ans;
  }
};
