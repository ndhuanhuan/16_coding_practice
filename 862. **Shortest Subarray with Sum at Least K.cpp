// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque
// https://buptwc.com/2018/07/02/Leetcode-862-Shortest-Subarray-with-Sum-at-Least-K/
// https://blog.csdn.net/Tc_To_Top/article/details/87081189

// 需要维护一个单调递增的deque。 为什么是递增的： 因为， 你需要用后面的数（和） 去减这个deque里的数来求解。 例子， 如果deque是【0，4，3】 为例， 
// 4 没有价值，因为假如未来有一个数 x， 且 x - 4 >= k， 那么， x-3 > k 也成立， 且 x和3的距离更短。 在这个例子中， 保存4 就没有了意义。
class Solution {
public:
    int shortestSubarray(vector<int> A, int K) {
        int N = A.size(), res = N + 1;
        vector<int> B(N + 1, 0);
        for (int i = 0; i < N; i++) B[i + 1] = B[i] + A[i];
        deque<int> d;
        for (int i = 0; i < N + 1; i++) {
            while (d.size() > 0 && B[i] - B[d.front()] >= K)
                res = min(res, i - d.front()), d.pop_front();
            while (d.size() > 0 && B[i] <= B[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};
