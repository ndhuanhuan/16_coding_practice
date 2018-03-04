//比如112045 当 i=4时候代表1120 有多少种解法， 相当于11+20的解法加上112+0的解法，由于0无法解析成字母所以112+0
//11+20就是dp[i-2], 112+0 就是dp[i-1]. 所以说，加不加dp[i-1]取决于s[i-1]是否为0.


class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]<'1'||s[0]>'9')
        {
            return 0;
        }
        vector<int> dp(s.size()+1,0);
        dp[0] = 1,dp[1]=1;
        for(int i=2; i<=s.size(); i++)
        {
            if(s[i-1]!='0')
                dp[i] = dp[i-1];
            else
                dp[i] = 0;
            int v = (s[i-2]-'0')*10+(s[i-1]-'0');
            if(v<=26&&v>9)
            {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
