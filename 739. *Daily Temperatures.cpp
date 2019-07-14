// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-739-daily-temperatures/
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    const int n = temperatures.size();
    stack<int> s;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && temperatures[s.top()] <= temperatures[i]) s.pop();
      ans[i] = s.empty() ? 0 : s.top() - i;
      s.push(i);
    }
    return ans;
  }
};
