// https://zxi.mytechroad.com/blog/searching/leetcode-818-race-car/
constexpr int kMaxT = 10000;
int m[kMaxT + 1][2]={0};
 
class Solution {
public:
  int racecar(int target) {
    if (m[1][0] == 0) {
      for (int t = 1; t <= kMaxT; ++t) {
        const int n = ceil(log2(t + 1));
        if (1 << n == t + 1) {
          m[t][0] = n;
          m[t][1] = n + 1;
          continue;
        }
        const int l = (1 << n) - 1 - t;
        m[t][0] = n + 1 + min(m[l][1], m[l][0] + 1);
        m[t][1] = n + 1 + min(m[l][0], m[l][1] + 1);
        for (int i = 1; i < t; ++i) { 
          const int mi = min(m[i][0] + 2, m[i][1] + 1);
          m[t][0] = min(m[t][0], m[t - i][0] + mi);
          m[t][1] = min(m[t][1], m[t - i][1] + mi);
        }
      }
    } 
    return min(m[target][0], m[target][1]);
  }
};
