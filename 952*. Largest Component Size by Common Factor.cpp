//https://zxi.mytechroad.com/blog/graph/leetcode-952-largest-component-size-by-common-factor/
class DSU {
public:
  DSU(int n): p_(n) {
    for (int i = 0; i < n; ++i)
      p_[i] = i;
  }
  
  void Union(int x, int y) {
    p_[Find(x)] = p_[Find(y)];
  }
  
  int Find(int x) {
    if (p_[x] != x) p_[x] = Find(p_[x]);
    return p_[x];
  }
private:
  vector<int> p_;
};
 
class Solution {
public:
  int largestComponentSize(vector<int>& A) {    
    int n = *max_element(begin(A), end(A));
    DSU dsu(n + 1);
    for (int a : A)
      for (int k = 2; k <= sqrt(a); ++k)
        if (a % k == 0) {
          dsu.Union(a, k);
          dsu.Union(a, a / k);
        }
    unordered_map<int, int> c;
    int ans = 1;
    for (int a : A)
      ans = max(ans, ++c[dsu.Find(a)]);    
    return ans;
  }  
};