// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/discuss/547225/C%2B%2B-with-picture%3A-track-direction-%2B-upscaled-grid
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> directs({
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{0, 1}, {-1, 0}}
        });

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> bfs;
        bfs.push({0, 0});
        visited[0][0] = true;
        while (!bfs.empty()) {
            vector<int> cur = bfs.front();
            bfs.pop();

            int row = cur[0];
            int col = cur[1];
            int type = grid[row][col] - 1;
            for (auto& dir : directs[type]) {
                int nr = row + dir[0];
                int nc = col + dir[1];
                if (nr < 0 or nr >= m or nc < 0 or nc >= n or visited[nr][nc]) {
                    continue;
                }

                for (auto& backDir : directs[grid[nr][nc] - 1])
                    if (nr + backDir[0] == row and nc + backDir[1] == col) {
                        visited[nr][nc] = true;
                        bfs.push({nr, nc});
                    }
            }
        }
        return visited[m - 1][n - 1];
    }
};
