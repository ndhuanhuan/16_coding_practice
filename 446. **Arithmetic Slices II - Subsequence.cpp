// https://www.cnblogs.com/grandyang/p/6057934.html
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)A[i] - A[j];
                if(diff > INT_MAX || diff < INT_MIN) continue;
                dp[i][diff] += 1;
                if(dp[j].count(diff)) {
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                
            }
        }
        return res;
    }
};
