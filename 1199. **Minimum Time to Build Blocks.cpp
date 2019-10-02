// https://leetcode.com/problems/minimum-time-to-build-blocks/discuss/387144/Java-Huffman's-Algorithm-with-Explanation-Video
// https://leetcode.com/problems/minimum-time-to-build-blocks/discuss/387051/JavaC%2B%2BPython-Huffman's-Algorithm
// https://leetcode.com/problems/minimum-time-to-build-blocks/discuss/387030/C%2B%2B-priority-queue-in-O(Nlog(N))
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num: blocks) {
            pq.push(num);
        }
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(b+split);
        }
        return pq.top();
    }
};
