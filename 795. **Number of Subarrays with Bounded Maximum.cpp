//https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117765/Simple-C++-(-EASY-to-understand-)-with-explanation
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt=0,lessThanLeft=0,lessThanOrEqToRight=0;
        for (auto n: A){
 
            if (n<L)
                ++lessThanLeft;
            else
                lessThanLeft=0;
            
            if (n<=R)
                ++lessThanOrEqToRight;
            else
                lessThanOrEqToRight=0;
            
            cnt+=lessThanOrEqToRight-lessThanLeft;
        }
        return cnt;
    }
};
