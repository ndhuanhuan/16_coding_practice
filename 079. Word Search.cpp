class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(); 
        if(m==0) return false; 
        int n=board[0].size(); 
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(dfs(board, i, j, word, 0))
                    return true;     
            }
        return false; 
    }
    
    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int index){
        if(index==word.size()) return true; 
        
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]!=word[index]) return false; 
        
        char ch=board[x][y]; 
        board[x][y]='#'; 
        
        bool ret= dfs(board, x-1, y, word, index+1) || dfs(board, x+1, y, word, index+1) || dfs(board, x, y+1, word, index+1) || dfs(board, x, y-1, word, index+1); 
        
      board[x][y]=ch; 
        
        return ret; 
        
        
    }
};
