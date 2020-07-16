// https://www.acwing.com/file_system/file/content/whole/index/content/1088098/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        int m = edges.size();
        vector<vector<pair<int, double>>> graph(n);

        for (int i = 0; i < m; i++) {
            int x = edges[i][0], y = edges[i][1];
            double s = succProb[i];
            graph[x].emplace_back(y, s);
            graph[y].emplace_back(x, s);
        }

        priority_queue<pair<double, int>> q;
        vector<double> dis(n, 0);
        vector<bool> vis(n, false);

        dis[start] = 1.0;
        q.push(make_pair(1.0, start));

        while (!q.empty()) {
            auto cur = q.top();
            q.pop();

            if (end == cur.second)
                return dis[end];

            if (vis[cur.second]) continue;
            vis[cur.second] = true;

            for (const auto &t : graph[cur.second])
                if (dis[t.first] < cur.first * t.second) {
                    dis[t.first] = cur.first * t.second;
                    q.push(make_pair(dis[t.first], t.first));
                }
        }

        return dis[end];
    }
};
