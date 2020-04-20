class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        if(nums.size() == 0) return -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[end]){ // there exists rotation; the middle element is in the left part of the array
                if((target >= nums[start]) && (target <= nums[mid])){
                    end = mid - 1;
                }
                else start = mid + 1;
            }
            else{//there exists rotation; the middle element is in the right part of the array
                if((target >= nums[mid]) && (target <= nums[end])){
                    start = mid + 1;
                }
                else end = mid - 1;
            }
        }
        return -1;
        
        }
};
