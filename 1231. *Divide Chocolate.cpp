// https://leetcode.com/problems/divide-chocolate/discuss/408503/JavaC%2B%2BPython-Binary-Search
class Solution {
public:
    int maximizeSweetness(vector<int>& A, int K) {
        int left = 1, right = 1e9 / (K + 1);
        while (left < right) {
            int mid = (left + right + 1) / 2;
            int cur = 0, cuts = 0;
            for (int a : A) {
                if ((cur += a) >= mid) {
                    cur = 0;
                    if (++cuts > K) break;
                }
            }
            if (cuts > K)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};
