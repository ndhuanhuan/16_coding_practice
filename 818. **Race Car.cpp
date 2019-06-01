// http://zxi.mytechroad.com/blog/graph/leetcode-818-race-car/
class Solution {
public:
  int racecar(int target) {
    m_ = vector<int>(target + 1, 0);
    return dp(target);
  }
private:
  vector<int> m_;
  int dp(int t) {
    if (m_[t] > 0) return m_[t];
    int n = ceil(log2(t + 1));
    // AA...A (nA) best case
    if (1 << n == t + 1) return m_[t] = n; 
    // AA...AR (nA + 1R) + dp(left) 
    m_[t] = n + 1 + dp((1 << n) - 1 - t);  
    for (int m = 0; m < n - 1; ++m) {
      int cur = (1 << (n - 1)) - (1 << m);
      //AA...ARA...AR (n-1A + 1R + mA + 1R) + dp(left) 
      m_[t] = min(m_[t], n + m + 1 + dp(t - cur)); 
    }
    return m_[t];  
  }
};
