// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-975-odd-even-jump/
class Solution {
public:
  int oddEvenJumps(vector<int>& A) {
    const int n = A.size();
    map<int, int> m;
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[n - 1][0] = dp[n - 1][1] = 1;
    m[A[n - 1]] = n - 1;  // for binary search
    int ans = 1;
    for (int i = n - 2; i >= 0; --i) {
      auto o = m.lower_bound(A[i]);
      if (o != m.end()) dp[i][0] = dp[o->second][1];  // i will be smaller than o->second, this line means up/odd status = future down/even status
      auto e = m.upper_bound(A[i]);
      if (e != m.begin()) dp[i][1] = dp[prev(e)->second][0];  // i will be smaller than o->second, this line means down/even status = future up/odd status
      if (dp[i][0]) ++ans; // it means you'll start from i, and it works, you can only start with odd/up jump
      m[A[i]] = i;
    }
    return ans;
  }
};
