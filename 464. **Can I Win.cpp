//http://zxi.mytechroad.com/blog/searching/leetcode-464-can-i-win/

class Solution {
public:
  bool canIWin(int M, int T) {
    const int sum = M * (M + 1) / 2;
    if (sum < T) return false;
    if (T <= 0) return true;
    m_ = vector<char>(1 << M, 0);
    return canIWin(M, T, 0);
  }
private:
  vector<char> m_; // 0: unknown, 1: won, -1: lost
  bool canIWin(int M, int T, int state) {
    if (T <= 0) return false;
    if (m_[state]) return m_[state] == 1;
    for (int i = 0; i < M; ++i) {
      if (state & (1 << i)) continue; // number i used      
      // The next player can not win, current player wins
      if (!canIWin(M, T - (i + 1), state | (1 << i))) 
        return m_[state] = 1;
    }
    // Current player loses.
    m_[state] = -1;
    return false;
  }
};

//http://www.cnblogs.com/grandyang/p/6103525.html
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    bool canWin(int length, int total, int used, unordered_map<int, bool>& m) {
        if (m.count(used)) return m[used];
        for (int i = 0; i < length; ++i) {
            int cur = (1 << i);
            if ((cur & used) == 0) {
                if (total <= i + 1 || !canWin(length, total - (i + 1), cur | used, m)) {
                    m[used] = true;
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
};
