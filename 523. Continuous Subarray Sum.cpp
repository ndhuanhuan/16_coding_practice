//http://www.cnblogs.com/grandyang/p/6504158.html
//那么我们需要一个变量pre来记录之前的和，我们每次存入set中的是pre，而不是当前的累积和
//原因是： 余数相同， 但是距离至少隔了1个数

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if (st.count(t)) return true;
            st.insert(pre);
            pre = t;
        }
        return false;
    }
};
