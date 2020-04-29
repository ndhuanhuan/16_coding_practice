// https://zxi.mytechroad.com/blog/hashtable/leetcode-1424-diagonal-traverse-ii/
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<vector<int>> m;    
    for (int i = 0; i < nums.size(); ++i)
      for (int j = 0; j < nums[i].size(); ++j) {
        if (m.size() <= i + j) m.push_back({});
        m[i + j].push_back(nums[i][j]);
    }
    vector<int> ans;    
    for (const auto& d : m)
      ans.insert(end(ans), rbegin(d), rend(d));
    return ans;
  }
};
