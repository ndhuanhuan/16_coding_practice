//http://www.cnblogs.com/grandyang/p/5677550.html
//http://blog.csdn.net/qq508618087/article/details/51991143
//http://fangde2.blogspot.com/2016/07/leetcode-q375-guess-number-higher-or.html
class Solution {
public:
    int getMoneyAmount(int n) {
        if(n==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>0;i--)
        {
            for(int j = i+1; j <=n; j++)  
            {  
                int ans = INT_MAX;  
                for(int k = i; k <j; k++)  
                    ans = min(ans, k + max(dp[i][k-1], dp[k+1][j]));  
                dp[i][j] = ans;  
            }   
        }
        return dp[1][n];
    }
};


class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        for(int i = 1; i <= n; ++i)
        {
            dp[i][i] = 0;
            if(i + 1 <= n)
            {
                dp[i][i+1] = i;   
            }
        }
        for(int len = 3; len <= n; ++len)
        {
            for(int left = 1; left + len - 1 <= n; ++left)
            {
                int right = left + len - 1;
                for(int mid = left + 1; mid < right; ++mid)
                {
                    dp[left][right] = min(dp[left][right], mid + max(dp[left][mid - 1], dp[mid + 1][right]));
                }
            }
        }
        return dp[1][n];
    }
};
