// https://www.cnblogs.com/grandyang/p/11048142.html
class Solution {
public:
    int superEggDrop(int K, int N) {
		vector<vector<int>> dp(N + 1, vector<int>(K + 1));
		int m = 0;
		while (dp[m][K] < N) {
			++m;
			for (int j = 1; j <= K; ++j) {
				dp[m][j] = dp[m - 1][j - 1] + dp[m - 1][j] + 1;
			}
		}
		return m;
    }
};

// 在某一层楼，仍鸡蛋，不管结果如何，都能帮助你了解蛋在第几层碎
// 鸡蛋碎掉：说明至少可以测到的不会碎的层数就是 dp[i-1][j-1]。
// 鸡蛋没碎：那这个鸡蛋可以继续利用，此时我们还可以再向上查找 dp[i-1][j] 层。
// +1 当前层你也测了， 加个1
