// https://zxi.mytechroad.com/blog/graph/leetcode-1202-smallest-string-with-swaps/
class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.length();
    vector<int> p(n);    
    iota(begin(p), end(p), 0); // p = {0, 1, 2, ... n - 1}
    
    function<int(int)> find = [&](int x) {
      return p[x] == x ? x : p[x] = find(p[x]);
    };        
    
    for (const auto& e : pairs)
      p[find(e[0])] = find(e[1]); // union
    
    vector<vector<int>> idx(n);
    vector<string> ss(n);
    
    for (int i = 0; i < s.length(); ++i) {
      int id = find(i);      
      idx[id].push_back(i); // already sorted
      ss[id].push_back(s[i]);
    }
    
    for (int i = 0; i < n; ++i) {      
      sort(begin(ss[i]), end(ss[i]));
      for (int k = 0; k < idx[i].size(); ++k)
        s[idx[i][k]] = ss[i][k];
    }
    
    return s;
  }
};
