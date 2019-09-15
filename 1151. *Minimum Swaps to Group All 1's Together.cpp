// Thinking about it: the final result we want is a window with length of n (total number of the 1s)
// Check all the window with the same length n, find the maximum one which already contains the most 1s.
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/discuss/355889/C%2B%2B-O(n)-time-O(1)-space
class Solution {
public:
    int minSwaps(vector<int>& data) {
        for(int i = 1; i < data.size(); ++i) {
            data[i] += data[i-1];
        }
        int K = data.back();
        if(K == 0)
            return 0;
        // count max number of 1 window size K has
        int max_one = data[K-1];
        for(int i = K; i < data.size(); ++i) {
            max_one = max(max_one, data[i] - data[i-K]);
        }
        return K - max_one;
    }
};
