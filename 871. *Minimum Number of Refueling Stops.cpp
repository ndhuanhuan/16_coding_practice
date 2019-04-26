// https://zxi.mytechroad.com/blog/?s=Minimum+Number+of+Refueling+Stops

// Method 1 DP
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    const int n = stations.size();
    // dp[i]: max distance to go with i stops.
    vector<long> dp(n + 1, startFuel);
    // For each station
    for (int i = 0; i < n; ++i) 
      // for j stops, start from high to low to avoid reusing station i
      for (int j = i + 1; j >= 1; --j) 
        if (dp[j - 1] >= stations[i][0])
          // if we can reach station i with j - 1 stops,
          // we can reach dp[j - 1] + station[i][1] with j stops.
          dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);
    
    for (int i = 0; i < dp.size(); ++i)
      if (dp[i] >= target) return i;
    return -1;
  }
};







// method 2 Priority Queue
class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int cur = startFuel;
    int stops = 0;
    int i = 0;
    priority_queue<int> q; // gas (high to low) of reachable stations.
    while (true) {
      if (cur >= target) return stops;
      while (i < stations.size() && stations[i][0] <= cur)
        q.push(stations[i++][1]); 
      if (q.empty()) break;
      cur += q.top(); q.pop();
      ++stops;
    }
    return -1;
  }
};

