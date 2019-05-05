// https://zxi.mytechroad.com/blog/string/leetcode-839-similar-string-groups/
class DSU {
public:
  DSU(int size):size_(size), parent_(size), rank_(size) {
    iota(begin(parent_), end(parent_), 0);
  }
  
  int Find(int n) {
    if (parent_[n] != n) 
      parent_[n] = Find(parent_[n]);
    return parent_[n];
  }
  
  void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    if (px == py) return;
    if (rank_[py] > rank_[px])
      swap(px, py);
    else if (rank_[py] == rank_[px])
      ++rank_[px];
    parent_[py] = px;
    --size_;
  }
  
  int Size() const {
    return size_;
  }
  
private:
  int size_;
  vector<int> rank_;
  vector<int> parent_;
};
 
class Solution {
public:
  int numSimilarGroups(vector<string>& A) {
    DSU dsu(A.size());
    for (int i = 0; i < A.size(); ++i)
      for (int j = i + 1; j < A.size(); ++j)
        if (similar(A[i], A[j]))
          dsu.Union(i, j);
    return dsu.Size();
  }
private:
  bool similar(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.length(); ++i)
      if (a[i] != b[i] && ++diff > 2) return false;    
    return true;
  }
};
