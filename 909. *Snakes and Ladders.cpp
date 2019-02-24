//  https://zxi.mytechroad.com/blog/searching/leetcode-909-snakes-and-ladders/
class Solution {
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    const int N = board.size();
    int steps = 0;
    vector<int> seen(N * N + 1, 0);
    queue<int> q;
    q.push(1);
    seen[1] = 1;
    while (!q.empty()) {
      int size = q.size();
      ++steps;
      while (size--) {
        int s = q.front(); q.pop();        
        for (int x = s + 1; x <= min(s + 6, N * N); ++x) {          
          int r, c;
          getRC(x, N, &r, &c);
          int nx = board[r][c] == -1 ? x : board[r][c];          
          if (seen[nx]) continue;
          if (nx == N * N) return steps;
          q.push(nx);
          seen[nx] = 1;
        } 
      }      
    }
    return -1;
  }
private:
  void getRC(int s, int N, int* r, int* c) {
    int y = (s - 1) / N;
    int x = (s - 1) % N;
    *r = N - 1 - y;
    *c = (y % 2) ?  N - 1 - x : x;
  }
};
