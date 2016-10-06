//http://www.cnblogs.com/grandyang/p/4325840.html
//如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int n=nums.size();
        if (n == 0) return false;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else if (nums[mid] > nums[right]){
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            } else --right;
        }
        return false;
        
    }
};
