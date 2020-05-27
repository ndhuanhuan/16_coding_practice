// https://zxi.mytechroad.com/blog/tree/leetcode-1273-delete-tree-nodes/
class Solution {
public:
  int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    vector<vector<int>> g(nodes);
    for (int i = 1; i < nodes; ++i)
      g[parent[i]].push_back(i);    
    // Returns <sum, nodes> of subtree n.
    function<pair<int,int>(int)> traverse = [&](int n) {
      int sum = value[n];
      int count = 1;
      for (int x : g[n]) {
        auto [s, c] = traverse(x);        
        sum += s;
        count += s ? c : 0;
      }
      return make_pair(sum, sum ? count : 0);
    };    
    return traverse(0).second;
  }
};
