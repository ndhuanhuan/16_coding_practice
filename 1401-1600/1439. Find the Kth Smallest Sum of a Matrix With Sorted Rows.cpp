// https://www.acwing.com/file_system/file/content/whole/index/content/513759/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        #define PIV pair<int, vector<int>>

        priority_queue<PIV, vector<PIV>, greater<PIV>> q;
        set<vector<int>> vis;

        vector<int> idx(m, 0);
        int sum = 0;

        for (int i = 0; i < m; i++)
            sum += mat[i][0];

        q.push(make_pair(sum, idx));

        while (--k) {
            sum = q.top().first;
            idx = q.top().second;

            q.pop();

            for (int i = 0; i < m; i++) {
                int j = idx[i];
                if (j + 1 < n) {
                    idx[i]++;
                    if (vis.find(idx) == vis.end()) {
                        vis.insert(idx);
                        q.push(make_pair(sum - mat[i][j] + mat[i][j + 1], idx));
                    }
                    idx[i]--;
                }
            }
        }

        return q.top().first;
    }
};

