// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-540-single-element-in-a-sorted-array/
// https://www.cnblogs.com/grandyang/p/7679036.html
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[mid ^ 1]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};
