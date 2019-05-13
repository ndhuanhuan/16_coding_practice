// https://zxi.mytechroad.com/blog/greedy/leetcode-826-most-profit-assigning-work/
class Solution {
public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    const int N = 100000;
    // max profit at difficulty i
    vector<int> max_profit(N + 1, 0);
    for (int i = 0; i < difficulty.size(); ++i)
      max_profit[difficulty[i]] = max(max_profit[difficulty[i]], profit[i]);
    for (int i = 2; i <= N; ++i)
      max_profit[i] = max(max_profit[i], max_profit[i - 1]);
    int ans = 0;
    for (int level : worker)
      ans += max_profit[level];
    return ans;
  }
};
