// https://www.cnblogs.com/grandyang/p/8387593.html
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        long mx = INT_MIN, secondMx = INT_MIN, mxId = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > mx) {
                secondMx = mx;
                mx = nums[i];
                mxId = i;
            } else if (nums[i] > secondMx) {
                secondMx = nums[i];
            }
        }
        return (mx - secondMx >= secondMx) ? mxId : -1;
    }
};
