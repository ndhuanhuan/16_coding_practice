// https://zxi.mytechroad.com/blog/queue/leetcode-1499-max-value-of-equation/
class Solution {
public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {    
    deque<pair<int, int>> q; // {y - x, x} Sort by y - x.
    int ans = INT_MIN;
    for (const auto& p : points) {
      const int xj = p[0];
      const int yj = p[1];
      // Remove invalid points, e.g. xj - xi > k
      while (!q.empty() && xj - q.front().second > k)
        q.pop_front();
      if (!q.empty())
        ans = max(ans, xj + yj + q.front().first);      
      while (!q.empty() && yj - xj >= q.back().first) 
        q.pop_back();
      q.emplace_back(yj - xj, xj);
    }
    return ans;
  }
};
