// https://leetcode.com/problems/path-sum-iv/discuss/106887/C%2B%2B-Java-Clean-Code
class Solution {
public:
    int pathSum(vector<int>& nums) {
        map<int, map<int, int>> m;
        for (int n : nums) {
            int i = n / 100 - 1; // i is 0 based index;
            int j = (n % 100) / 10 - 1; // j used 0 based index;
            int v = n % 10;
            m[i][j] = m[i - 1][j / 2] + v;
        }

        int sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                sum += m[i][j] && !m[i + 1][j * 2] && !m[i + 1][j * 2 + 1] ? m[i][j] : 0;
            }
        }
        return sum;
    }
};
