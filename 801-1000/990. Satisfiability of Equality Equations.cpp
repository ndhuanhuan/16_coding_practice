//https://zxi.mytechroad.com/blog/graph/leetcode-990-satisfiability-of-equality-equations/
class Solution {
public:
  bool equationsPossible(vector<string>& equations) {        
    iota(begin(parents_), end(parents_), 0);    
    for (const auto& eq : equations)     
      if (eq[1] == '=')
        parents_[find(eq[0])] = find(eq[3]);
    for (const auto& eq : equations)     
      if (eq[1] == '!' && find(eq[0]) == find(eq[3]))        
          return false;
    return true;
  }
private:
  array<int, 128> parents_;
  int find(int x) {
    if (x != parents_[x])
      parents_[x] = find(parents_[x]);
    return parents_[x];
  }  
};
