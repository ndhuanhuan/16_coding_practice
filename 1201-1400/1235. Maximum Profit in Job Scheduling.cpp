// https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1235-maximum-profit-in-job-scheduling/
class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    const int n = startTime.size();  
    vector<vector<int>> jobs(n);
    for (int i = 0; i < n; ++i)
      jobs[i] = {endTime[i], startTime[i], profit[i]};
    sort(begin(jobs), end(jobs));
    
    int ans = 0;
    map<int, int> m{{0, 0}}; // {end_time -> max_profit}
    for (const auto& job : jobs) {
      int p = prev(m.upper_bound(job[1]))->second + job[2];
      if (p > rbegin(m)->second) {
        m[job[0]] = p;
      }      
    }
    return rbegin(m)->second;
  }
};
