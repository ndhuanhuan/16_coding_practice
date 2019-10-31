// https://zxi.mytechroad.com/blog/brute-force/leetcode-1237-find-positive-integer-solution-for-a-given-equation/
class Solution {
public:
  vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> ans;    
    for (int x = 1; x <= 1000; ++x) {
      if (customfunction.f(x, 1) > z) break;
      for (int y = 1; y <= 1000; ++y) {
        int t = customfunction.f(x, y);
        if (t > z) break;
        if (t == z) ans.push_back({x, y});        
      }
    }
    return ans;
  }
};
