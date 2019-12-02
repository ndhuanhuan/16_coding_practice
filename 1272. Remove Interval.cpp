// https://zxi.mytechroad.com/blog/geometry/leetcode-1272-remove-interval/
class Solution {
public:
  vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& r) {
    vector<vector<int>> ans;
    for (const auto& i : intervals)
      // Does not intersect
      if (i[1] <= r[0] || i[0] >= r[1])
        ans.push_back(i);
      else {
        // i starts first
        if (i[0] < r[0]) 
          ans.push_back({i[0], r[0]});
        // i ends later
        if (i[1] > r[1])
          ans.push_back({r[1], i[1]});        
      }
    return ans;
  }
};
