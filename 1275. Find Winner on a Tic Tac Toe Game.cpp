// https://zxi.mytechroad.com/blog/simulation/leetcode-1275-find-winner-on-a-tic-tac-toe-game/
class Solution {
public:
  string tictactoe(vector<vector<int>>& moves) {
    vector<vector<string>> b(3, vector<string>(3, "#"));
    bool A = true;
    for (const auto& move : moves) {
      b[move[0]][move[1]] = A ? "A" : "B";
      A = !A;
    }
    for (int i = 0; i < 3; ++i) {
      if (b[i][0] == b[i][1] && b[i][2] == b[i][1] && b[i][0] != "#")
        return b[i][0];
      if (b[0][i] == b[1][i] && b[2][i] == b[1][i] && b[0][i] != "#")
        return b[0][i];
    }
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[1][1] != "#")
      return b[1][1];
    if (b[2][0] == b[1][1] && b[1][1] == b[0][2] && b[1][1] != "#")
      return b[1][1];
    return moves.size() == 9 ? "Draw" : "Pending";
  }
};
