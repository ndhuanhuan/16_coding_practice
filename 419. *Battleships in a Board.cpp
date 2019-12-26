// https://zxi.mytechroad.com/blog/leetcode/leetcode-battleships-in-a-board/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[i].size();++j) {
                if(board[i][j] == 'X'
                   && (i==0 || board[i-1][j] == '.')
                   && (j==0 || board[i][j-1] == '.')) ++count;
            }
        return count;
    }
};
