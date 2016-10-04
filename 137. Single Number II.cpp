//http://bangbingsyb.blogspot.com/2014/11/leetcode-single-number-i-ii.html
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int n=nums.size();
        int res = 0;
        for(int i=31; i>=0; i--) {
            int sum = 0;
            int mask = 1<<i;
            for(int j=0; j<n; j++) {
                if(nums[j] & mask) 
                    sum++;
            }
            res = (res<<1) + (sum%3);
        }
        return res;
    }
};
