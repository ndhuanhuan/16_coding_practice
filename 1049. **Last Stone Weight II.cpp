// Our goal is to minimize psum - (sum(stones)-psum) = 2*psum - sum(stones)
// https://leetcode.com/problems/last-stone-weight-ii/discuss/294888/JavaC%2B%2BPython-Easy-Knapsacks-DP
// https://leetcode.com/problems/last-stone-weight-ii/discuss/294881/Another-kind-of-coin-change-problem
class Solution {
public:
    int lastStoneWeightII(vector<int> A) {
        bitset<1501> dp = {1};
        int sumA = 0, res = 100;
        for (int a : A) {
            sumA += a;
            for (int i = sumA; i >= a; --i)
                dp[i] = dp[i] + dp[i - a];
        }
        for (int i = sumA / 2; i > 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;
    }
};
