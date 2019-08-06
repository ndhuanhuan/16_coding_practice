// https://leetcode.com/problems/previous-permutation-with-one-swap/discuss/299215/JavaC%2B%2BPython-When-Leetcode-Was-Wrong
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size(), left = n - 2, right = n - 1;
        while (left >= 0  && A[left] <= A[left + 1]) left--;
        if (left < 0) return A;
        while (A[left] <= A[right]) right--;
        while (A[right - 1] == A[right]) right--; // already sorted (increase) at right side of left pointer, this while loop is trying to skip duplicate values
        swap(A[left], A[right]);
        return A;
    }
};
