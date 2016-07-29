
//http://www.cnblogs.com/grandyang/p/5411919.html
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp{0, 0, 1, 2, 4, 6, 9};
        for (int i = 7; i <= n; ++i) {
            dp.push_back(3 * dp[i - 3]);
        }
        return dp[n];
    }
};
