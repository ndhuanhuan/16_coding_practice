// https://www.acwing.com/solution/LeetCode/content/3838/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.length(),n = key.length(),cost = 0,res = INT_MAX;
        // m => ring, n => key
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // cache matched indices
        vector<int> lastMatched, temp;
        
        for(int i = 0; i < m; ++i) {
            if(ring[i] == key[0]) {
                dp[0][i] = min(i+1, m-i+1);
                temp.push_back(i);
            }
        }
        
        for(int i = 1 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                dp[i][j] = INT_MAX;
                
                if(key[i] == ring[j])
                {
                    for(auto lastMatchedIndex: temp) {
                        cost = dp[i - 1][lastMatchedIndex] + min((j - lastMatchedIndex + m) % m,(lastMatchedIndex - j + m) % m) + 1;
                        dp[i][j] = min(dp[i][j],cost);
                        
                    }
                    lastMatched.push_back(j);
                }
            }
            temp.swap(lastMatched);
            lastMatched.clear();
        }
        for(int i = 0; i < m ; i ++)
            if(ring[i] == key[n - 1])
                res = min(res,dp[n - 1][i]);
        return res;
    }
};
