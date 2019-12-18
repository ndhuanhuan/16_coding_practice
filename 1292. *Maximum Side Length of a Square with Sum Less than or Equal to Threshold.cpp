// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/discuss/451909/C%2B%2B-Two-O(MN)-Solutions.-PrefixSum-%2B-SlidingWindow-or-PrefixSum-%2B-Smart-Enumeration
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1292-maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
class Solution {
    int squareSum(vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
        return prefixSum[x2][y2] - prefixSum[x1][y2] - prefixSum[x2][y1] + prefixSum[x1][y1];
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefixSum(m+1, vector<int>(n+1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int res = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int len = res+1;
                while (i+len <= m && j+len <= n && squareSum(prefixSum, i, j, i+len, j+len) <= threshold) {
                    res = len;
                    len++;
                }
            }
        }
        return res;
    }
};
