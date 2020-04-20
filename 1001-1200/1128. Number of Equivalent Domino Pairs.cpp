// https://leetcode.com/problems/number-of-equivalent-domino-pairs/discuss/340022/JavaC%2B%2BPython-Easy-and-Concise
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int res = 0;
        for (auto& d : dominoes) {
            res += count[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;
        }
        return res;
    }
};
