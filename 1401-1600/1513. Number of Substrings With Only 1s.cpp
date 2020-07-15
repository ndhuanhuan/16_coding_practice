// https://leetcode.com/problems/number-of-substrings-with-only-1s/discuss/731580/JavaC%2B%2BPython-Count
class Solution {
public:
    int numSub(string s) {
        int res = 0, count = 0, mod = 1e9 + 7;
        for (char c: s) {
            count = c == '1' ? count + 1 : 0;
            res = (res + count) % mod;
        }
        return res;
    }
};
