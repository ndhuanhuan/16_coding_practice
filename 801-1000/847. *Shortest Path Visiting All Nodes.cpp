// https://zxi.mytechroad.com/blog/graph/leetcode-847-shortest-path-visiting-all-nodes/
class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    const int n = graph.size();
    const int kAns = (1 << n) - 1;
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(1 << n));
    for (int i = 0; i < n; ++i)
      q.push({i, 1 << i});
    int steps = 0;
    while (!q.empty()) {
      int s = q.size();
      while (s--) {
        auto p = q.front(); 
        q.pop();
        int node = p.first;
        int state = p.second;
        if (state == kAns) return steps;   
        if (visited[node][state]) continue;
        visited[node][state] = 1;
        for (int next : graph[node])
          q.push({next, state | (1 << next)});
      }
      ++steps;
    }
    return -1;
  }
};
