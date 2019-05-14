// https://leetcode.com/problems/card-flipping-game/discuss/125791/C%2B%2BJavaPython-Easy-and-Concise-with-Explanation
// https://zxi.mytechroad.com/blog/greedy/leetcode-822-card-flipping-game/
class Solution {
public:
  int flipgame(vector<int>& fronts, vector<int>& backs) {
    unordered_set<int> same;
    for (int i = 0; i < fronts.size(); ++i)
      if (fronts[i] == backs[i])
        same.insert(fronts[i]);
    
    int ans = INT_MAX;
    for (int v : fronts)
      if (v < ans && !same.count(v)) ans = v;
    
    for (int v : backs)
      if (v < ans && !same.count(v)) ans = v;
    
    return ans == INT_MAX ? 0 : ans;
  }
};
