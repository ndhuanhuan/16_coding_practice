// https://zxi.mytechroad.com/blog/math/leetcode-789-escape-the-ghosts/
class Solution {
public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    const int steps = abs(target[0]) + abs(target[1]);
    for (const auto& g: ghosts)
      if (abs(g[0] - target[0]) + abs(g[1] - target[1]) <= steps) 
        return false;
    return true;
  }
};
