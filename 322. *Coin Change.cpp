//https://www.hrwhisper.me/leetcode-coin-change/
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		const int INF = 0x7fffffff;
		vector<int> dp(amount + 1, INF);
		dp[0] = 0;
		for (int i = 0; i <= amount; i++) {
			for (int j = 0; j<coins.size(); j++) {
				if (i + coins[j] <= amount && dp[i]!= INF && dp[i + coins[j]] > dp[i] + 1)
					dp[i + coins[j]] =dp[i] + 1;
			}
		}
		return dp[amount] == INF ? -1 : dp[amount];
	}
};


//http://www.cnblogs.com/grandyang/p/5138186.html
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
