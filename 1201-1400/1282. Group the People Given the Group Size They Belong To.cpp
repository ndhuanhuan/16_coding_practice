// https://zxi.mytechroad.com/blog/hashtable/leetcode-1282-group-the-people-given-the-group-size-they-belong-to/
class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector<vector<int>> ans;
    const int n =  groupSizes.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
      auto& v = m[groupSizes[i]];
      v.push_back(i);
      if (v.size() == groupSizes[i])
        ans.push_back(std::move(v));                       
    }
    return ans;
  }
};
