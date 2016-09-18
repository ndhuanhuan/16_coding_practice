//http://www.cnblogs.com/grandyang/p/5327635.html
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
    }
    bool helper(vector<int> &preorder, int start, int end, int lower, int upper) {
        if (start > end) return true;
        int val = preorder[start], i = 0;
        if (val <= lower || val >= upper) return false;
        for (i = start + 1; i <= end; ++i) {
            if (preorder[i] >= val) break;
        }
        return helper(preorder, start + 1, i - 1, lower, val) && helper(preorder, i, end, val, upper);
    }
};
