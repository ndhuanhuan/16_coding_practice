// https://leetcode.com/problems/fixed-point/discuss/303401/JavaC%2B%2BPython-Binary-Search-0-in-Ai-i

class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int l = 0, r = A.size() - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (A[m] - m < 0)  //this is the core part of this LC problem 
                l = m + 1;
            else
                r = m;
        }
        return A[l] == l ? l : -1;
    }
};
