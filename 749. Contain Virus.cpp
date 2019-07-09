// https://zxi.mytechroad.com/blog/searching/leetcode-749-contain-virus/
class Solution {
public:
  int containVirus(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int total_walls = 0;
    while (true) {            
      vector<int> visited(m * n, 0);
      vector<int> virus_area;
      vector<unordered_set<int>> nexts;
      int block_index = -1;
      int block_walls = -1;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          int key = i * n + j;
          if (grid[i][j] != 1 || visited[key]) continue;
          vector<int> curr;
          unordered_set<int> next;
          int walls = 0;
          getArea(j, i, m, n, grid, visited, curr, next, walls);
          if (next.empty()) continue;                    
          if (nexts.empty() || next.size() > nexts[block_index].size()) {
            virus_area.swap(curr);
            block_index = nexts.size();
            block_walls = walls;
          }
          nexts.push_back(std::move(next));
        }
 
      if (nexts.empty()) break;
 
      total_walls += block_walls;
      for (int i = 0; i < nexts.size(); ++i) {
        if (i == block_index) {
          for (const int key : virus_area) {
              int y = key / n;
              int x = key % n;
              grid[y][x] = 2; // blocked.
          }
        } else {
          for (const int key : nexts[i]) {
              int y = key / n;
              int x = key % n;
              grid[y][x] = 1; // newly affected
          }
        }
      }
    }
    return total_walls;
  }
private:
  void getArea(
    int x, int y, int m, int n,
    vector<vector<int>>& grid,
    vector<int>& visited,
    vector<int>& curr,
    unordered_set<int>& next,
    int& walls) {
    static int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
 
    if (x < 0 || x >= n || y < 0 || y >= m || grid[y][x] == 2) return;
 
    int key = y * n + x;
    // need one wall
    if (grid[y][x] == 0) {
      ++walls;
      next.insert(key);
      return;
    }
 
    if (visited[key]) return;
    visited[key] = 1;
    curr.push_back(key);    
 
    for (int i = 0; i < 4; ++i)
      getArea(x + dirs[i][0], y + dirs[i][1], m, n, grid, visited, curr, next, walls);
  }
};
