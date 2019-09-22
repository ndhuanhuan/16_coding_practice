// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1184-distance-between-bus-stops/
class Solution {
public:
  int distanceBetweenBusStops(vector<int>& ds, int s, int d) {    
    if (s > d) swap(s, d);
    int sum = accumulate(begin(ds), end(ds), 0);
    int d1 = accumulate(begin(ds) + s, begin(ds) + d, 0);
    return min(d1, sum - d1);
  }
};
