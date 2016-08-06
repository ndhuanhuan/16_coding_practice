//https://www.hrwhisper.me/leetcode-burst-balloons/
//https://discuss.leetcode.com/topic/30746/share-some-analysis-and-explanations
class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        return DP(1,n,nums,dp);
    }
    
    int DP(int i,int j, const vector<int>& nums, vector<vector<int>> &dp)
    {
        if(dp[i][j]>0) return dp[i][j];
        for(int x=i;x<=j;x++)
        {
            int temp = DP(i,x-1,nums,dp)+nums[i-1]*nums[x]*nums[j+1]+ DP(x + 1, j, nums, dp);
            if(temp>dp[i][j]) dp[i][j] = temp;
        }
        return dp[i][j];
        
    }
};
