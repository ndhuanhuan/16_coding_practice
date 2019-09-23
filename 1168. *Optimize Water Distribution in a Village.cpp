// https://leetcode.com/problems/optimize-water-distribution-in-a-village/discuss/365853/C%2B%2BPythonJava-Hidden-Well-in-House-0
class Solution {
public:
    vector<int> uf;
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        uf.resize(n + 1, 0);
        for (auto& p : pipes) swap(p[0], p[2]);
        for (int i = 0; i < n; ++i) {
            uf[i + 1] = i + 1;
            pipes.push_back({wells[i], 0, i + 1});
        }
        sort(pipes.begin(), pipes.end());

        int res = 0;
        for (int i = 0; n > 0; ++i) {
            int x = find(pipes[i][1]), y = find(pipes[i][2]);
            if (x != y) {
                res += pipes[i][0];
                uf[x] = y;
                --n;
            }
        }
        return res;
    }

    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};
