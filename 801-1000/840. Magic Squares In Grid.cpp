
// https://www.cnblogs.com/grandyang/p/10404157.html
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (grid[i + 1][j + 1] == 5 && isValid(grid, i, j)) ++res;
            }
        }
        return res;
    }
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        vector<int> cnt(10);
        for (int x = i; x < i + 2; ++x) {
            for (int y = j; y < j + 2; ++y) {
                int k = grid[x][y];
                if (k < 1 || k > 9 || cnt[k] == 1) return false;
                cnt[k] = 1;
            }
        }
        if (15 != grid[i][j] + grid[i][j + 1] + grid[i][j + 2]) return false;
        if (15 != grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2]) return false;
        if (15 != grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2]) return false;
        if (15 != grid[i][j] + grid[i + 1][j] + grid[i + 2][j]) return false;
        if (15 != grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1]) return false;
        if (15 != grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2]) return false;
        if (15 != grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]) return false;
        if (15 != grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2]) return false;
        return true;
    }
};
