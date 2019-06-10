// https://www.cnblogs.com/grandyang/p/10285531.html
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), m = n / 2, sum = accumulate(A.begin(), A.end(), 0);
        bool possible = false;
        for (int i = 1; i <= m && !possible; ++i) {
            if (sum * i % n == 0) possible = true;
        }
        if (!possible) return false;
        vector<unordered_set<int>> dp(m + 1);
        dp[0].insert(0);
        for (int num : A) {
            for (int i = m; i >= 1; --i) {
                for (auto a : dp[i - 1]) {
                    dp[i].insert(a + num);
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (sum * i % n == 0 && dp[i].count(sum * i / n)) return true;
        }
        return false;
    }
};
