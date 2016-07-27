//https://www.hrwhisper.me/leetcode-count-numbers-unique-digits/
//http://www.cnblogs.com/grandyang/p/5582633.html
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += count(i);
        }
        return res;
    }
    int count(int k) {
        if (k < 1) return 0;
        if (k == 1) return 10;
        int res = 1;
        for (int i = 9; i >= (11 - k); --i) {
            res *= i;
        }
        return res * 9;
    }
};

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
