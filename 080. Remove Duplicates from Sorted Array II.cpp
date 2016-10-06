//http://www.cnblogs.com/grandyang/p/4329295.html
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return n;
        int pre = 0, cur = 1, count = 1;
        while (cur < n) {
            if (nums[pre] == nums[cur] && count == 0) ++cur;
            else {
                if (nums[pre] == nums[cur]) --count;
                else count = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return pre + 1;
    }
};
