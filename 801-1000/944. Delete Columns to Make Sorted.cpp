class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        const int n = A.size();
        if(n==0) return ans;
        for(int c = 0; c < A[0].size(); ++c) {
            for(int r = 1; r < n; ++r) {
                if(A[r][c] < A[r-1][c]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
