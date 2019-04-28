// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/141768/Detailed-explanation-O(NlogN)
class Solution {
public:
    double mincostToHireWorkers(vector<int> q, vector<int> w, int K) {
        vector<vector<double>> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.push_back({(double)(w[i]) / q[i], (double)q[i]});   // push ratio, quality pair
        sort(workers.begin(), workers.end());           // sort by ratio
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker: workers) {
            qsum += worker[1], pq.push(worker[1]);         //push quality into PQ
            if (pq.size() > K) qsum -= pq.top(), pq.pop();     // pop with largest quality
            if (pq.size() == K) res = min(res, qsum * worker[0]); // since it is sorted, worker[0] is the largest ratio in PQ (currently), PQ * totalQuantity
        }
        return res;
    }
};
