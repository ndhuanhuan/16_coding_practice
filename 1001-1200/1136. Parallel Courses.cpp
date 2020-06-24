// https://leetcode.com/problems/parallel-courses/discuss/345015/C%2B%2B-dfs-15-line-and-bfs-15-line
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations)
    {
        vector<int> vDepth(N, 1), visitState(N, 0); // visite state  -1 :visiting;  0:not visit;  1:visited
        vector<vector<int>> g(N);
        for (auto& v : relations) g[v[0] - 1].push_back(v[1] - 1);
        for (int i = 0; i < N; i++) if (!dfs(i, g, vDepth, visitState)) return -1;
        return *max_element(vDepth.begin(), vDepth.end());
    }

    // return false if there is a circle
    bool dfs(int i, const vector<vector<int>> & g, vector<int> & vDepth, vector<int> & visitState) {
        if (visitState[i] == 1) return true;
        if (visitState[i] == -1) return false; // circle  
        visitState[i] = -1; //visiting
        for (auto j : g[i]) {
            if (!dfs(j, g, vDepth, visitState)) return false;
            vDepth[i] = max(vDepth[i], 1 + vDepth[j]);
        }
        visitState[i] = 1; //visited;
        return true;
    }
};
