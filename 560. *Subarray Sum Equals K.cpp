// https://zxi.mytechroad.com/blog/hashtable/leetcode-560-subarray-sum-equals-k/
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    unordered_map<int, int> counts{{0,1}};
    int cur_sum = 0;
    int ans = 0;
    for (const int num : nums) {
      cur_sum += num;      
      ans += counts[cur_sum - k];
      ++counts[cur_sum];
    }
    return ans;
  }
};
