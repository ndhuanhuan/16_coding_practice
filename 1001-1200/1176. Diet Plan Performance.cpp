// https://zxi.mytechroad.com/blog/sliding-window/leetcode-1176-diet-plan-performance/
class Solution {
public:
  int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int ans = 0;
    int t = accumulate(begin(calories), begin(calories) + k - 1, 0);
    for (int i = k - 1; i < calories.size(); ++i) {
      if (i >= k) t -= calories[i - k];
      t += calories[i];
      if (t > upper) ++ans;
      if (t < lower) --ans;      
    }
    return ans;
  }
};
