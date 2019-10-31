// https://leetcode.com/problems/circular-permutation-in-binary-representation/discuss/414203/JavaC%2B%2BPython-4-line-Gray-Code
// https://cp-algorithms.com/algebra/gray-code.html
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        for (int i = 0; i < 1 << n; ++i)
            res.push_back(start ^ i ^ i >> 1);
        return res;
    }
};
