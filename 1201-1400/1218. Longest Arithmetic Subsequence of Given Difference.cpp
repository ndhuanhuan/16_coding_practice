// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1218-longest-arithmetic-subsequence-of-given-difference/
class Solution {
public:
  int longestSubsequence(vector<int>& arr, int d) {
    unordered_map<int, int> dp;
    int ans = 0;
    for (int x : arr)      
      ans = max(ans, dp[x] = dp[x - d] + 1);    
    return ans;
  }
}
