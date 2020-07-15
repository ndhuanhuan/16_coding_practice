// https://leetcode.com/problems/number-of-good-pairs/discuss/731561/JavaC%2B%2BPython-Count
class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> count;
        for (int a: A) {
            res += count[a]++;
        }
        return res;
    }
};
