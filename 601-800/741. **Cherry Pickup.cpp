// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-741-cherry-pickup/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int n = grid.size();
        grid_ = &grid;
        m_ = vector<vector<vector<int>>>(
                n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, dp(n - 1, n - 1, n - 1));
    }
private:
    // max cherries from (x1, y1) to (0, 0) + (x2, y2) to (0, 0)
    int dp(int x1, int y1, int x2) {
        const int y2 = x1 + y1 - x2;
        if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return -1;
        if ((*grid_)[y1][x1] < 0 || (*grid_)[y2][x2] < 0) return -1;
        if (x1 == 0 && y1 == 0) return (*grid_)[y1][x1];
        if (m_[x1][y1][x2] != INT_MIN) return m_[x1][y1][x2];        
        int ans =  max(max(dp(x1 - 1, y1, x2 - 1), dp(x1, y1 - 1, x2)),
                       max(dp(x1, y1 - 1, x2 - 1), dp(x1 - 1, y1, x2)));
        if (ans < 0) return m_[x1][y1][x2] = -1;
        ans += (*grid_)[y1][x1];
        if (x1 != x2) ans += (*grid_)[y2][x2];
        
        return m_[x1][y1][x2] = ans;
    }
    
    vector<vector<vector<int>>> m_;
    vector<vector<int>>* grid_; // does not own the object
};
