class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {    
    vector<State> states(graph.size(), UNKNOWN);
    vector<int> ans;
    for (int i = 0; i < graph.size(); ++i)      
      if (dfs(graph, i, states) == SAFE)
        ans.push_back(i);
    return ans;
  }
private:
  enum State {UNKNOWN, VISITING, SAFE, UNSAFE};
  State dfs(const vector<vector<int>>& g, int cur, vector<State>& states) {
    if (states[cur] == VISITING)
      return states[cur] = UNSAFE;
    if (states[cur] != UNKNOWN)
      return states[cur];
    states[cur] = VISITING;
    for (int next : g[cur])
      if (dfs(g, next, states) == UNSAFE) 
        return states[cur] = UNSAFE;
    return states[cur] = SAFE;
  }
};
