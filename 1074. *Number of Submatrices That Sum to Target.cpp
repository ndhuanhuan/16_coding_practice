// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/303750/JavaC%2B%2BPython-Find-the-Subarray-with-Target-Sum
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] += A[i][j - 1];    // accumulate columns
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_map<int, int> counter;
                counter[0] = 1;
                int cur = 0;
                for (int k = 0; k < m; k++) {      // accumulate rows
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += counter[cur - target];  // see example
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};


// example approach number 4

// https://leetcode.com/problems/subarray-sum-equals-k/solution/
