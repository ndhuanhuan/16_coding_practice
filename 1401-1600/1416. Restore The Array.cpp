// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1416-restore-the-array/
class Solution {
public:
    int numberOfArrays(string s, int k) {
        constexpr int kMod = 1e9 + 7;
        const int n = s.length();
        vector<int> dp(n+1, 0);
        dp.back() = 1;
        
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == '0') continue;
            long num = 0;
            for(int j = i +1; j <= n; ++j) {
                num = num * 10 + (s[j-1] - '0');
                if(num > k) break;
                dp[i] = (dp[i] + dp[j]) % kMod;
            }
        }
        
        return dp[0];
    }
};
