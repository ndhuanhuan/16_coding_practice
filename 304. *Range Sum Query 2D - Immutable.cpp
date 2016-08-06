//http://blog.csdn.net/liyuefeilong/article/details/50761072
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        sumRecord = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        // 由于sumRegion函数可能被调用多次，因此使用辅助数组sumRecord用于
        // 记录matrix中坐标(0,0)到任一下标(i,j)之间矩形框内元素的值，这样
        // 每次调用sumRegion函数时只需查询sumRecord里的值并进行简单运算即可
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                sumRecord[i][j] = matrix[i - 1][j - 1] + sumRecord[i - 1][j] + sumRecord[i][j - 1] - sumRecord[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumRecord[row2 + 1][col2 + 1] - sumRecord[row1][col2 + 1] - sumRecord[row2 + 1][col1] + sumRecord[row1][col1];
    }

private:
    vector<vector<int>> sumRecord;
};
