// https://zxi.mytechroad.com/blog/graph/leetcode-1319-number-of-operations-to-make-network-connected/
class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    vector<int> p(n);
    iota(begin(p), end(p), 0);
    
    function<int(int)> find = [&](int x) {
      return p[x] == x ? x : p[x] = find(p[x]);
    };
    
    for (const auto& c : connections)
      p[find(c[0])] = find(c[1]);    
    
    unordered_set<int> s;
    for (int i = 0; i < n; ++i)
      s.insert(find(i));
    
    return s.size() - 1;        
  }
};
