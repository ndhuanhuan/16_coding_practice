// https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/260916/Proof%3A-we-only-need-to-consider-the-first-K-candidates-in-1-11-111-1111-...
// https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/260852/JavaC%2B%2BPython-O(1)-Solution-with-Proves
class Solution {
public:
    int smallestRepunitDivByK(int K) {
         if (K % 2 == 0 || K % 5 == 0) return -1;
        for (int r = 0, N = 1; N <= K; ++N)
            if ((r = (r * 10 + 1) % K) == 0)
                return N;
        return -1;
    }
};
