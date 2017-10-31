class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        while (exc) {
            ++res;
            exc &= (exc - 1);
        }
        return res;
    }
};
