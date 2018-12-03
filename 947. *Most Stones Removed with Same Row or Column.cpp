//https://zxi.mytechroad.com/blog/graph/leetcode-947-most-stones-removed-with-same-row-or-column/
class Solution {
public:
  int removeStones(vector<vector<int>>& stones) {
    const int kSize = 10000;
    DSU dsu(kSize * 2);
    for (const auto& stone : stones)
      dsu.Union(stone[0], stone[1] + kSize);
    unordered_set<int> seen;
    for (const auto& stone : stones)
      seen.insert(dsu.Find(stone[0]));
    return stones.size() - seen.size();
  }
private:
  class DSU {
  public:
    DSU(int n): p_(n) {
      for (int i = 0 ; i < n; ++i)
        p_[i] = i;              
    }
    
    void Union(int i, int j) {
      p_[Find(i)] = Find(j);      
    }
    
    int Find(int i) {
      if (p_[i] != i) p_[i] = Find(p_[i]);
      return p_[i];
    }    
  private:
    vector<int> p_;    
  };
};
