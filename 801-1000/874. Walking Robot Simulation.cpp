class Solution {
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int x = 0;
    int y = 0;
    int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // WNES
    int d = 1;
    unordered_map<int, unordered_set<int>> o;
    for (const auto obstacle : obstacles)
      o[obstacle[0]].insert(obstacle[1]);
    int ans = 0;
    for (int c : commands) {      
      if (c == -2)
        d = (d - 1 + 4) % 4;
      else if (c == -1)
        d = (d + 1) % 4;
      else {
        while (c--) {
          int tx = x + dirs[d][0];
          int ty = y + dirs[d][1];
          if (o.count(tx) && o.at(tx).count(ty))
            break;
          x = tx;
          y = ty;
          ans = max(ans, x * x + y * y);          
        }
      }
    }
    return ans;
  }
};
