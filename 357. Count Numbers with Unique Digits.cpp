//https://www.hrwhisper.me/leetcode-count-numbers-unique-digits/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(n,10);
        vector<int> dp(n + 1, 9);
        dp[0] = 1;
        for(int i = 1;i<n;i++){
            for(int x = 9; x >= 9 - i + 1;x--){
                dp[i] *= x;
            }
        }
        int ans = 0;
        for(int i= 0;i<dp.size();i++) ans += dp[i];
        return ans;
    }
};
