class Solution {
public:
    int mxgold = 0;
    int gold(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>> &visited)
    {
        if(i<0 || j<0 || i>=n || j >=m || visited[i][j] == false || grid[i][j] ==0)
                return 0;
        visited[i][j] = false;
        
        int a = gold(i+1,j,n,m,grid,visited);
        int b = gold(i-1,j,n,m,grid,visited);
        int c = gold(i,j+1,n,m,grid,visited);
        int d = gold(i,j-1,n,m,grid,visited);

        visited[i][j] = true;
        int num = max(a,max(b,max(c,d))) + grid[i][j];
        mxgold = max(mxgold, num);
        return num;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m,true));
            
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] != 0 && visited[i][j] == true)
                {
                    gold(i,j,n,m,grid,visited);
                }
            }
        }
        return mxgold;
    }
};