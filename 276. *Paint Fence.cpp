//http://www.cnblogs.com/grandyang/p/5231220.html
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        int same = 0, diff = k, res = same + diff;
        for (int i = 2; i <= n; ++i) {
            same = diff;
            diff = res * (k - 1); // this guarantee that ABCDE, DE is not same color.
            res = same + diff;
        }
        return res;
    }
};
