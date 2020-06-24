// https://zxi.mytechroad.com/blog/uncategorized/leetcode-1443-minimum-time-to-collect-all-apples-in-a-tree/
class Solution {
public:
  int minTime(int n, vector<vector<int>>& edges, 
              vector<bool>& hasApple) {
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    vector<int> seen(n);    
    function<int(int)> dfs = [&] (int cur) {
      seen[cur] = 1;
      int total = 0;      
      for (int child : g[cur]) {
        if (seen[child]) continue;        
        int cost = dfs(child);
        if (cost > 0 || hasApple[child])          
          total += 2 + cost;        
      }      
      return total;
    };    
    return dfs(0);    
  }
};
