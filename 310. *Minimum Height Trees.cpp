//http://www.cnblogs.com/grandyang/p/5000291.html
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n==1) return {0};
        vector<int> res, d(n,0);
        vector<vector<int>> g(n,vector<int>());
        queue<int> q;
        for(auto a:edges)
        {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
            ++d[a.first];
            ++d[a.second];
        }
        
        for(int i=0;i<n;++i)
        {
            if(d[i]==1) q.push(i);
        }
         while (n > 2) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int t = q.front(); q.pop();
                --n;
                for (int i : g[t]) {
                    --d[i];
                    if (d[i] == 1) q.push(i);
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};
