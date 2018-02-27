//sample 9 ms submission
//http://www.cnblogs.com/grandyang/p/4402656.html
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        if (grid.empty() || grid[0].empty())
            return 0;
        
        
        //find first land
        
        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfsSweep(grid, i, j);
                    islandCount++;
                }
            } //end for j
        }// end for i
       
      return islandCount;  
    }
void dfsSweep(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != '1')
        return;

    if (grid[r][c] == '0')
        return;
    
    grid[r][c] = '0';

    //top
    dfsSweep(grid, r-1,c);
    //left
    dfsSweep(grid, r, c-1);
    //right
    dfsSweep(grid, r, c+1);
    //bottom
    dfsSweep(grid, r+1,c);
}
};
