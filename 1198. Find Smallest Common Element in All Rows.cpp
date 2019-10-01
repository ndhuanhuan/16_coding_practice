class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& A) {
        vector<int> count(10001);
        int n = A.size(), m = A[0].size();
        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                if (++count[A[i][j]] == n)
                    return A[i][j];
        return -1;
    }
};
