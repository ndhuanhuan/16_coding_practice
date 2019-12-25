// https://zxi.mytechroad.com/blog/geometry/leetcode-452-minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(), 
         [&](const vector<int>& a, const vector<int>& b){
           return a[1] < b[1];
         });
    int right = points.front()[1];
    int ans = 1;
    for (const auto& point : points) {
      if (point[0] > right) {
        right = point[1];
        ++ans;
      }
    }
    return ans;
  }
};
