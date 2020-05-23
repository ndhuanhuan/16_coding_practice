// https://www.acwing.com/solution/LeetCode/content/5099/
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int>> f(n, vector<int>(n, n));
        for (int i = 0; i < n; i++)
            f[i][i] = 0;

        for (int i = 1; i < n; i++)
            f[i][i - 1] = 0;

        for (int len = 2; len <= n; len++)
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1];
                else
                    f[i][j] = min(f[i][j - 1] + 1, f[i + 1][j] + 1);
            }

        return f[0][n - 1] <= k;
    }
};
