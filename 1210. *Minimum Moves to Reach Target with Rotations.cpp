// https://zxi.mytechroad.com/blog/searching/leetcode-1210-minimum-moves-to-reach-target-with-rotations/
class Solution {
public:
  inline int pos(int x, int y) {
    return y * 100 + x;
  }
  
  inline int encode(int p1, int p2) {
    return (p1 << 16) | p2;
  }
  
  int minimumMoves(vector<vector<int>>& grid) {    
    int n = grid.size();
    queue<pair<int, int>> q;
    unordered_set<int> seen;
    q.push({pos(0, 0), pos(1, 0)}); // tail, head
    seen.insert(encode(pos(0, 0), pos(1, 0)));
    int steps = 0;
    auto valid = [&](int x, int y) {
      bool v = x >= 0 && x < n && y >= 0 && y < n && !grid[y][x];      
      return v;
    };
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto p = q.front(); q.pop();
        int y0 = p.first / 100;
        int x0 = p.first % 100;
        int y1 = p.second / 100;
        int x1 = p.second % 100;
                        
        if (x0 == n - 2 && y0 == n - 1 &&
            x1 == n - 1 && y1 == n - 1) {
          return steps;
        }
        
        bool h = y0 == y1;        
        
        for (int i = 0; i < 3; ++i) {
          int tx0 = x0;
          int ty0 = y0;
          int tx1 = x1;
          int ty1 = y1;
          int rx = x0;
          int ry = y0;
          switch (i) {
            case 0: // down              
              ++ty0;
              ++ty1;
              break;
            case 1: // right
              ++tx0;
              ++tx1;
              break;
            case 2: // rotate              
              ++rx;  // Trick: when rotate, make sure right two or bottom two cell are 0 not just "one" cell is 0
              ++ry;
              if (h) { // clockwise 
                --tx1;
                ++ty1;
              } else { // counterclockwise  
                ++tx1;
                --ty1;
              }
              break;
          }                    
          if (!valid(tx0, ty0) || !valid(tx1, ty1) || !valid(rx, ry)) continue;          
          int key = encode(pos(tx0, ty0), pos(tx1, ty1));
          if (seen.count(key)) continue;
          seen.insert(key);
          q.push({pos(tx0, ty0), pos(tx1, ty1)});
        }
      }
      ++steps;
    }
    return -1;
  }
};
