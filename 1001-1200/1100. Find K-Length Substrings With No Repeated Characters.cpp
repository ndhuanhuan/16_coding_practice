// https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/discuss/322928/JavaC%2B%2BPython-Sliding-Window
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        unordered_set<int> cur;
        int res = 0, i = 0;
        for (int j = 0; j < S.size(); ++j) {
            while (cur.count(S[j]))
                cur.erase(S[i++]);
            cur.insert(S[j]);
            res += j - i + 1 >= K;
        }
        return res;
    }
};
