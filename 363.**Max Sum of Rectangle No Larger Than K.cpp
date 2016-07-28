//lower_bound 是下界不是 去寻找这个数， 是找到下界index
//http://www.cnblogs.com/grandyang/p/5617660.html
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            vector<int> sum(m, 0);
            for (int j = i; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    sum[k] += matrix[k][j];
                }
                int curSum = 0, curMax = INT_MIN;
                set<int> s;
                s.insert(0);
                for (auto a : sum) {
                    curSum += a;
                    auto it = s.lower_bound(curSum - k);
                    if (it != s.end()) curMax = max(curMax, curSum - *it);
                    s.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};
