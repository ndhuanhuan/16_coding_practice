// https://www.acwing.com/solution/LeetCode/content/429/
class Solution {
public:
    const int MOD = 1000000007;
    int f[100010][2][3];
    int checkRecord(int n) {
        f[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++)
                for (int k = 0; k <= 2; k++) {
                    f[i + 1][j][0] = (f[i + 1][j][0] + f[i][j][k]) % MOD;
                    if (k < 2)
                        f[i + 1][j][k + 1] = (f[i + 1][j][k + 1] + f[i][j][k]) % MOD;
                    if (j < 1)
                        f[i + 1][j + 1][0] = (f[i + 1][j + 1][0] + f[i][j][k]) % MOD;
                }
        }

        int ans = 0;
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 2; k++)
                ans = (ans + f[n][j][k]) % MOD;
        return ans;
    }
};
