//http://blog.csdn.net/nk_test/article/details/49518487
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        if(n < 3)  
            return n;  
        int index = 2;  
        for(int i = 2; i < n; i ++)  
        {  
            if(nums[i] != nums[index-2])  
                nums[index ++] = nums[i];  
        }  
        return index;  
    }
};

