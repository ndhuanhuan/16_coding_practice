// https://leetcode.com/problems/path-with-maximum-minimum-value/discuss/323062/C%2B%2B-200ms-solution-based-on-Dijkstra's-Algorithm
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int direct[4][2] = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
        priority_queue<array<int, 3>> pq;
        vector<vector<int>> val(A.size(), vector<int>(A[0].size()));
        val[0][0] = A[0][0];
        array<int, 3> start = {A[0][0], 0, 0};
        pq.push(start);
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            for (int i=0; i<4; i++) {
                int x = top[1]+direct[i][0];
                int y = top[2]+direct[i][1];
                if (x<0||y<0||x>=A.size()||y>=A[0].size())
                    continue;
                int cur_val = min(top[0], A[x][y]);
                if (x==A.size()-1&&y==A[0].size()-1)
                    return cur_val;
                else if (cur_val<=val[x][y])
                    continue;
                else {
                    val[x][y] = cur_val;
                    array<int, 3> cur = {cur_val, x, y};
                    pq.push(cur);
                }
            }
        }
        return val.back().back();
    }
};
