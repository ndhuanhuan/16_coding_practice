// https://zxi.mytechroad.com/blog/searching/leetcode-1376-time-needed-to-inform-all-employees/
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> es(n);
        for (int i = 0; i < n; ++i) {
            if (i != headID) {
              es[manager[i]].push_back(i); 
            }

        }
        function<int(int)> dfs = [&](int cur) {
                int t = 0;
                for (int e : es[cur])
                    t = max(t, dfs(e));
                return t + informTime[cur];
            };
        return dfs(headID);        
    }
};
