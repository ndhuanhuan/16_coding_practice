// https://leetcode.com/problems/new-21-game/discuss/132334/One-Pass-DP-O(N)
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(N >= K + W || K== 0) return 1.0;
        vector<double> dp(N+1);
        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;
        // maximum draw N times
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i < K) Wsum += dp[i]; else res += dp[i]; // it compare with K !!! we only care about dp[i] which i in range [K, N], so we only start adding dp[i] when i is >=K
            if (i - W >= 0) Wsum -= dp[i - W];
        }
        return res;
    }
};
