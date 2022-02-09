class Solution {
public:
    vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int,int>> q;
    void dfs(int sr, int sc,vector<vector<int>>&grid)
    {
        grid[sr][sc]=0;
        q.push({sr,sc});
        for(auto ele: dir)
        {
            int r=sr+ele[0];
            int c=sc+ele[1];
            if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r][c]==1)
            {
                dfs(r,c,grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        bool oneFound =0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid);
                    oneFound=1;
                    break;
                }
            }
            if(oneFound) break;
        }
        
        int ans=-1;
        
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            while(size--)
            {
                auto p=q.front();
                q.pop();
                for(auto ele: dir)
                {
                    int r=p.first+ele[0];
                    int c=p.second+ele[1];
                    
                    if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size())
                    {
                        if(grid[r][c]==0)
                        {
                            q.push({r,c});
                            grid[r][c]=-1;
                        }
                        if(grid[r][c]==1)
                        {
                            return ans;
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};