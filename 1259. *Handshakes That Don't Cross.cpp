// Just think about the first people, 
// he's hand will split the others (exclude himself and his partner) into two groups (left, right).
// so the total number of handshakes will be the num of left group times the number of right group.
// and loop over all the possible splits.
class Solution {
public:
    int numberOfWays(int n) {
        long mod = 1e9 + 7;
        vector<long> dp(n / 2 + 1);
        dp[0] = 1L;
        for (int k = 1; k <= n / 2; ++k) {
            for (int i = 0; i < k; ++i) {
                dp[k] = (dp[k] + dp[i] * dp[k - 1 - i]) % mod;
            }
        }
        return dp[n / 2];
    }
};
