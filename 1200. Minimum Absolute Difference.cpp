// https://zxi.mytechroad.com/blog/greedy/leetcode-1200-minimum-absolute-difference/
class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(begin(arr), end(arr));
    vector<vector<int>> ans;
    int best = INT_MAX;
    for (int i = 1; i < arr.size(); ++i) {
      int d = abs(arr[i] - arr[i - 1]);      
      if (d < best) {
        ans.clear();
        best = d;
      }
      if (d == best) ans.push_back({arr[i - 1], arr[i]});      
    }
    return ans;
  }
};
