// https://zxi.mytechroad.com/blog/greedy/leetcode-1505-minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
class Fenwick {
 public:
  explicit Fenwick(int n) : sums_(n + 1) {}
  
  void update(int i, int delta) {
    ++i;
    while (i <  sums_.size()) {
      sums_[i] += delta;
      i += i & -i;
    }
  }
  
  int query(int i) {
    ++i;
    int ans = 0;
    while (i > 0) {
      ans += sums_[i];
      i -= i & -i;
    }
    return ans;
  }
 private:
  vector<int> sums_;
};
 
class Solution {
public:
  string minInteger(string num, int k) {    
    const int n = num.length();
    vector<queue<int>> pos(10);
    for (int i = 0; i < n; ++i)
      pos[num[i] - '0'].push(i);    
    
    Fenwick tree(n);
    vector<int> used(n);
    string ans;
    while (k > 0 & ans.length() < n) {      
      for (int d = 0; d < 10; ++d) {
        if (pos[d].empty()) continue;
        const int i = pos[d].front();
        const int cost = i - tree.query(i - 1);
        if (cost > k) continue;        
        k -= cost;
        ans += ('0' + d);
        tree.update(i, 1);
        used[i] = true;
        pos[d].pop();
        break;
      }
    };
    
    for (int i = 0; i < n; ++i)
      if (!used[i]) ans += num[i];
    return ans;
  }
};
