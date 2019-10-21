// https://leetcode.com/problems/toss-strange-coins/discuss/408485/JavaC%2B%2BPython-DP
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<double> dp(target + 1);
        dp[0] = 1.0;
        for (int i = 0; i < prob.size(); ++i)
            for (int k = min(i + 1, target); k >= 0; --k)
                dp[k] = (k ? dp[k - 1] : 0) * prob[i] + dp[k] * (1 - prob[i]);
        return dp[target];
    }
};
