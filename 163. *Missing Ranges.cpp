//http://www.voidcn.com/blog/pointbreak1/article/p-4357136.html
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if(nums.size() == 0) {
            if(lower == upper) 
                result.push_back(to_string(lower));
            else
                result.push_back(to_string(lower) + "->" + to_string(upper));
            return result;
        }
        
        if(nums[0] - lower > 1) 
            result.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
        else if(nums[0] - lower == 1) 
            result.push_back(to_string(lower));
            
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i - 1] > 2)
                result.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
            else if(nums[i] - nums[i - 1] == 2)
                result.push_back(to_string(nums[i - 1] + 1));
        }
        
        if(upper - nums[nums.size() - 1] > 1)
            result.push_back(to_string(nums[nums.size() - 1] + 1) + "->" + to_string(upper));
        else if(upper - nums[nums.size() - 1] == 1)
            result.push_back(to_string(upper));
        return result;
    }
};
