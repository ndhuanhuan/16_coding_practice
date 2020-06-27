// https://www.acwing.com/file_system/file/content/whole/index/content/554615/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, 
                    vector<vector<int>>& prerequisites,
                    vector<vector<int>>& queries) {

        vector<vector<int>> graph(n);

        for (const auto &v : prerequisites)
            graph[v[0]].push_back(v[1]);

        vector<vector<bool>> tra(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);

            tra[i][i] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u])
                    if (!tra[i][v]) {
                        tra[i][v] = true;
                        q.push(v);
                    }
            }
        }

        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
            ans[i] = tra[queries[i][0]][queries[i][1]];

        return ans;
    }
};
