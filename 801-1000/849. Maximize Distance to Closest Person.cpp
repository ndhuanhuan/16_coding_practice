// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-849-maximize-distance-to-closest-person/
class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    int prev = -1;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      if (i == n) ans = max(ans, n - prev - 1);
      else if (seats[i]) {
        if (prev == -1) ans = i;
        else ans = max(ans, (i - prev) / 2);
        prev = i;
      }
    }
    return ans;
  }
};
