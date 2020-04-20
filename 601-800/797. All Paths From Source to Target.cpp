// https://zxi.mytechroad.com/blog/graph/leetcode-797-all-paths-from-source-to-target/
class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {    
    vector<vector<int>> ans;
    vector<int> path{0};     
    dfs(graph, path, ans);
    return ans;
  }
private:
  void dfs(const vector<vector<int>>& graph, 
           vector<int>& path, vector<vector<int>>& ans) {
    if (path.back() == graph.size() - 1) {
      ans.push_back(path);
      return;
    }
    
    for (int next : graph[path.back()]) {
      path.push_back(next);
      dfs(graph, path, ans);
      path.pop_back();
    }
  }
};
