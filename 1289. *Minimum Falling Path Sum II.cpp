// https://leetcode.com/problems/minimum-falling-path-sum-ii/discuss/451706/c%2B%2B-DP-N2-36ms
// similar to paint house II
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int R = A.size();
        for(int i=1;i<R;++i){
            int fMin = INT_MAX, sMin = fMin;
            for(int j=0;j<R;++j){
                if(A[i-1][j]<fMin)  sMin=fMin,fMin=A[i-1][j];
                else if(A[i-1][j]<sMin) sMin=A[i-1][j];
            }
            for(int j=0;j<R;++j){
                A[i][j]+=A[i-1][j]==fMin?sMin:fMin;
            }
        }
        return *min_element(begin(A[R-1]),end(A[R-1]));
    }
};
