// https://leetcode.com/problems/find-the-index-of-the-large-integer/discuss/763124/JavaC%2B%2BCPython-Binary-Search
class Solution {
public:
    int getIndex(ArrayReader &rd) {
        int l = 0, r = rd.length() - 1;
        while (l < r) {
            int h = (r - l + 1) / 2; // half, h * 2 <= r - l + 1
            if (rd.compareSub(l, l + h - 1, l + h, l + h * 2 - 1) != 1)
                l = l + h;
            else
                r = l + h - 1;
        }
        return l;
    }
};
