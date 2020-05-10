//https://zxi.mytechroad.com/blog/searching/967-numbers-with-same-consecutive-differences/
class Solution {
public:
  vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> ans;
    if (N == 1) ans.push_back(0);
    for (int i = 1; i <= 9; ++i)
      dfs(N - 1, K, i, ans);
    return ans;
  }
private:
  void dfs(int N, int K, int cur, vector<int>& ans) {
    if (N == 0) {     // because of this logic, when trigger dfs in numsSameConsecDiff function, it uses N-1 instead of N
      ans.push_back(cur);
      return;
    }
    int l = cur % 10;
    if (l + K < 10)
      dfs(N - 1, K, cur * 10 + l + K, ans);
    if (l >= K && K != 0)  // tricky, K!=0, otherwise there will be duplicate results
      dfs(N - 1, K, cur * 10 + l - K, ans);
  }
};
