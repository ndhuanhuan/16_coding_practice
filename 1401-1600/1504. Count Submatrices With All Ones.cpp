// https://www.acwing.com/file_system/file/content/whole/index/content/1075030/
class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j- 1] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int res = 0;
        for (int row = 1; row <= m; ++row) {
            for (int len = 1; row + len - 1 <= m; ++len) {
                for (int col = 1; col <= n; ++col) {
                    if (getSum(preSum, row, col, row + len - 1, col) == len) {
                        int tmp = col;
                        while (tmp <= n && getSum(preSum, row, tmp, row + len - 1, tmp) == len) ++tmp;
                        int length = tmp - col;
                        res += (1 + length) * length / 2;
                        col = tmp - 1;
                    }
                }
            }
        }

        return res;
    }

    inline int getSum(vector<vector<int>> & preSum, int x1, int y1, int x2, int y2)
    {
        return preSum[x2][y2] - preSum[x1 - 1][y2] - preSum[x2][y1 - 1] + preSum[x1 - 1][y1 - 1];
    }
};
