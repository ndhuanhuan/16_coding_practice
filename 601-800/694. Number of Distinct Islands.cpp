class Solution {
private:
    vector<int> path_features;
    vector<int> dx={0,0,-1,1};
    vector<int> dy={1,-1,0,0};
public:
    void Dfs(vector<vector<int>>& grid, int x,int y,int path_num)
    {
        if(x<0 || x>=grid.size() || y<0 || y>= grid[0].size() || grid[x][y]==0)
            return;
        
        grid[x][y]=0;
        
        path_features.push_back(path_num);
        
        for(int i=0;i<4;++i)
        {
            Dfs(grid,x+dx[i],y+dy[i],i);
        }
        
        path_features.push_back(-1);
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        
        set<vector<int>> path_set;
        
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]==1)
                {
                    vector<int> vec_empty;
                    path_features=vec_empty;
                    Dfs(grid,i,j,-1);
                    path_set.insert(path_features);
                }
            }
        
        return path_set.size();
    }
};
