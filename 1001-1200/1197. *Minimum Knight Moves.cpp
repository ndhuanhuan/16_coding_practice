// https://github.com/vincivans/LeetCode/blob/3f3160894eb31eb46b1b50c987f27817d6ed0e94/1197minKnightMoves.cpp
class Solution {
public:
    int minKnightMoves(int x, int y) {
        int res = 0, n = 400;
        x=abs(x), y=abs(y);
        if(x==0 && y==0) return res;
        vector<int> dirx{-2,-2, -1,-1, 1,1, 2,2};
        vector<int> diry{-1, 1, -2, 2,-2,2,-1,1};
        queue<pair<int, int>> q{{{0, 0}}};
        vector<vector<int>> visited(n, vector<int>(n, -1));
        visited[0][0] = 0;
        while(!q.empty()) {
            if(visited[x][y] != -1)
                return visited[x][y];
            int xx = q.front().first, yy = q.front().second;
            q.pop();
            for(int d = 0; d < 8; ++d) {
                int dx = abs(xx+dirx[d]), dy = abs(yy+diry[d]);
                if(dx>=0 && dy>=0 && dx<n && dy<n && visited[dx][dy]==-1) {
                    visited[dx][dy] = visited[xx][yy]+1;
                    q.push({dx, dy});
                }
            }
        }
        return visited[x][y];
    }
};
