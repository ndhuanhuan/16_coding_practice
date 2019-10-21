// https://leetcode.com/problems/missing-number-in-arithmetic-progression/discuss/408474/JavaC%2B%2BPython-Arithmetic-Sum-and-Binary-Search
class Solution {
public:
    int missingNumber(vector<int>& A) {
        int n = A.size(), d = (A[n - 1] - A[0]) / n, left = 0, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] == A[0] + d * mid)
                left = mid + 1;
            else
                right = mid;
        }
        return A[0] + d * left;
    }
};
