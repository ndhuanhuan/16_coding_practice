// https://leetcode.com/problems/longest-repeating-substring/discuss/303884/easy-to-understand-N2-solution
// https://leetcode.com/problems/longest-repeating-substring/discuss/308999/C%2B%2B-dp-5-lines-O(n2)
class Solution {
public:
    int longestRepeatingSubstring(string S) {
       int n = S.size(),  maxLen = 0;
       vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
       for (int i = 0; i < n; i++)  for (int j = 0; j < i; j++)
           if (S[i] == S[j]) maxLen = max(maxLen, dp[i + 1][j + 1] = 1 + dp[i][j]);
       return maxLen;
    }
};
