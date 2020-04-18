
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int temp = 0;
        int minNum = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            temp += nums[i];
            minNum = min(temp, minNum);
        }
        
        return 1 - minNum <= 1 ? 1 : 1 - minNum;
    }
};
