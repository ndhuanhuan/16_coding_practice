// https://zxi.mytechroad.com/blog/tree/leetcode-1483-kth-ancestor-of-a-tree-node/
class TreeAncestor {
public:
  TreeAncestor(int n, vector<int>& parent):  g_(n), nodes_(n), levels_(n) {    
    for (int i = 1; i < n; ++i)
      g_[parent[i]].push_back(i);
    int id = 0;
    dfs(0,0, id);    
    // for(int i=0; i < nodes_.size(); i++)
    //     cout << nodes_[i].first << ' ' << nodes_[i].second << endl;
  }
 
  int getKthAncestor(int node, int k) {
    const auto [d, id] = nodes_[node];
    if (k > d) return -1;
    const auto& ns = levels_[d - k];
    return upper_bound(begin(ns), end(ns), pair{id, -1})->second;
  }
private:    
  void dfs(int node, int depth, int& id) {
    for (int c : g_[node]) dfs(c, depth + 1, ++id);    
    levels_[depth].emplace_back(id, node);
    nodes_[node] = {depth, id};
  }  
  vector<vector<int>> g_; // p -> {{child}}
  vector<vector<pair<int, int>>> levels_; // depth -> {{id, node}}
  vector<pair<int, int>> nodes_; // node -> {depth, id}
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
