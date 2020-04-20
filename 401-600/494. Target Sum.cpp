//http://www.cnblogs.com/grandyang/p/6395843.html
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int num : nums) {
            unordered_map<int, int> t;
            for (auto a : dp) {
                int sum = a.first, cnt = a.second;
                t[sum + num] += cnt;
                t[sum - num] += cnt;
            }
            dp = t;
        }
        return dp[S];
    }
};



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      const int n = nums.size();
      const int sum = std::accumulate(nums.begin(), nums.end(), 0);
      if (sum < S) return 0;
      const int offset = sum;
      // ways[i][j] means total ways to sum up to (j - offset) using nums[0] ~ nums[i - 1].
      vector<vector<int>> ways(n + 1, vector<int>(sum + offset + 1, 0));
      ways[0][offset] = 1;  // offset range from [-sum, sum] which map to index [0, sum * 2], so ways[0][offset] maps to use first 0 numbers to sum up to 0.
      for (int i = 0; i < n; ++i) {
        for (int j = nums[i]; j < 2 * sum + 1 - nums[i]; ++j)
          if (ways[i][j]) {
            ways[i + 1][j + nums[i]] += ways[i][j];
            ways[i + 1][j - nums[i]] += ways[i][j];
          }        
      }
      
      return ways.back()[S + offset];
    }
};
