
// https://leetcode.com/problems/image-overlap/discuss/130623/C%2B%2BJavaPython-Straight-Forward
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> LA, LB;
        int N = A.size();
        unordered_map<int, int> count;
        for (int i = 0; i < N * N; ++i) if (A[i / N][i % N] == 1) LA.push_back(i / N * 100 + i % N); //new representation of image
        for (int i = 0; i < N * N; ++i) if (B[i / N][i % N] == 1) LB.push_back(i / N * 100 + i % N);
        for (int i: LA) for (int j: LB) count[i - j]++;  // count[i-j] will be the 1's with same shifting
        int res = 0;
        for (auto it: count) res = max(res, it.second);  //find max count[i-j] value which is the shift we want
        return res;
    }
};
