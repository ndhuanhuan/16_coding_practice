//http://www.cnblogs.com/grandyang/p/4409379.html
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[right] != target) return res;
        res[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right= mid;
        }
        res[1] = left - 1;
        return res;
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        const int n = nums.size();
        int left=0, right = n-1;
        while(left<right)
        {
            int mid = (left+right)/2;
            if(nums[mid]<target) left = mid+1;
            else right = mid;
        }
        if(nums[left]!=target) return res;
        res[0]=left;
        right = n-1;  // We don't have to set i to 0 the second time.
        while (left < right)
        {
            int mid = (left + right) /2 + 1;	// Make mid biased to the right
            if (nums[mid] > target) right = mid - 1;  
            else left = mid;				// So that this won't make the search range stuck.
        }
        res[1]=right;
        return res;
    }
};



