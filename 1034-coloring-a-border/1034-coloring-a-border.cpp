class Solution {
public:
    vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    int vis[51][51];
    bool isBorder(vector<vector<int>>& grid1,int i,int j,int color)
    {
        if(i==0 or i==grid1.size()-1 or j==0 or j==grid1[0].size()-1) return true;
        
        if(i+1 < grid1.size() && grid1[i+1][j]!=color ) return true;
         if(i-1 >=0  && grid1[i-1][j]!=color ) return true;
         if(j+1 < grid1[0].size() && grid1[i][j+1]!=color ) return true;
         if(j-1 >=0 && grid1[i][j-1]!=color ) return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<int>> grid1, int sr,int sc, int prevColor, int newColor)
    {
        cout<<sr<<" "<<sc<<"\n";
        vis[sr][sc]=1;
        if(isBorder(grid1, sr,sc,prevColor))
            grid[sr][sc]=newColor;
        for(auto ele: dir)
        {
            int r= sr+ele[0];
            int c=sc+ele[1];
            if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r][c]==prevColor and !vis[r][c])
                dfs(grid,grid1,  r,c,prevColor, newColor);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size(), m=grid[0].size();
        memset(vis, 0,sizeof(vis));
        int prevColor = grid[row][col];
        dfs(grid , grid, row, col, prevColor, color);
        return grid;
    }
};