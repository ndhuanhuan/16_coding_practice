// https://zxi.mytechroad.com/blog/leetcode/leetcode-422-find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto num : nums) {
            int index = abs(num)-1;
            if (nums[index] < 0)
                ans.push_back(index+1);
            nums[index]*=-1;
        }
        return ans;
    }
};
