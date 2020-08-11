// https://leetcode.com/problems/kth-missing-positive-number/discuss/780201/Java-O(lgN)-binary-Search
class Solution {
public:
  int findKthPositive(vector<int>& A, int k) {
        int l = 0, r = A.size(), m;
        while (l < r) {
            m = (l + r) / 2;

            if (A[m] - 1 - m < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
};

// l is number of valid numbers already filed, k is to be filled. So it is l + k.
// Plus, A[l]'s left side has k nuumbers to be filled.
