// https://zxi.mytechroad.com/blog/greedy/leetcode-1353-maximum-number-of-events-that-can-be-attended/
class Solution {
public:
  int maxEvents(vector<vector<int>>& events) {
    sort(begin(events), end(events), [](const auto& a, const auto& b){      
      return a[1] < b[1];      
    });
    int ans = 0;
    int seen[100001] = {0};
    for (const auto& e : events) {
      for (int i = e[0]; i <= e[1]; ++i) {
        if (seen[i]) continue;
        ++seen[i];
        ++ans;
        break;
      }
    }
    return ans;
  }
};
