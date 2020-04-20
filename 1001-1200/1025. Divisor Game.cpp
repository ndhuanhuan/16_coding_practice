// https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-132/
class Solution {
public:
  bool divisorGame(int N) {
    cache_ = vector<int>(N + 1, -1);
    return canWin(N);
  }
private:
  vector<int> cache_;
  bool canWin(int N) {
    if (N == 1) return false;
    if (cache_[N] != -1) return cache_[N];
    bool win = false;
    for (int i = 1; i < N; ++i)
      if (N % i == 0)
        win |= !canWin(N - i);
    return cache_[N] = win;
  }
};
