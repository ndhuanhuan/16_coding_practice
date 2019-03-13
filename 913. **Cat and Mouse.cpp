//https://www.acwing.com/solution/leetcode/content/556/

class Solution {
public:
    vector<vector<vector<int>>> f;
    int solve(const vector<vector<int>>& graph, int t, int x, int y) {
        if (t == graph.size() * 2)
            return 0;
        if (x == y)
            return f[t][x][y] = 2;
        if (x == 0)
            return f[t][x][y] = 1;
        if (f[t][x][y] != -1)
            return f[t][x][y];


        int who = t % 2;
        bool flag;
        if (who == 0) { // Mouse goes next
            flag = true; // All ways are 2
            for (int i = 0; i < graph[x].size(); i++) {
                int nxt = solve(graph, t + 1, graph[x][i], y);
                if (nxt == 1)
                    return f[t][x][y] = 1;
                else if (nxt != 2)
                    flag = false;
            }
            if (flag)
                return f[t][x][y] = 2;
            else
                return f[t][x][y] = 0;
        }
        else { // Cat goes next
            flag = true; // All ways are 1
            for (int i = 0; i < graph[y].size(); i++)
                if (graph[y][i] != 0) {
                    int nxt = solve(graph, t + 1, x, graph[y][i]);
                    if (nxt == 2)
                        return f[t][x][y] = 2;
                    else if (nxt != 1)
                        flag = false;
                }
            if (flag)
                return f[t][x][y] = 1;
            else
                return f[t][x][y] = 0;
        }

    }

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        f = vector<vector<vector<int>>>(2 * n, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(graph, 0, 1, 2);
    }
};
