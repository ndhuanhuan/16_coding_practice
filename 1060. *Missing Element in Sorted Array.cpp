// https://leetcode.com/problems/missing-element-in-sorted-array/solution/
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k > missing(n-1, nums)) {
            return nums[n-1] + k - missing(n-1, nums);
        }
        
        int left = 0, right = n - 1, pivot;
        // find left = right index such that 
        // missing(left - 1) < k <= missing(left)
        while (left != right) {
          pivot = left + (right - left) / 2;

          if (missing(pivot, nums) < k) left = pivot + 1;
          else right = pivot;
        }

        // kth missing number is larger than nums[idx - 1]
        // and smaller than nums[idx]
        return nums[left - 1] + k - missing(left - 1, nums);
    }
private:
    int missing(int idx, vector<int>& nums) {
        return nums[idx] - nums[0] - idx;
    }
};
