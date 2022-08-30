class Solution {
public:
    
    int  bfs(vector<vector<int>>&grid, queue<pair<int,int>>q , vector<vector<int>>vis){
        int count = 0;;
        while(!q.empty()){
            int x = q.size();
            count++;
            for(int i=0;i<x;i++){
                pair<int,int>p= q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
    
                vis[r][c] = 0;  ////   is wale part ko kause handle karu /////// 
                if(r-1 >=0 && vis[r-1][c]==-1){
                    vis[r-1][c]=0;
                    q.push({r-1 , c});
                }
                if(r+1 < grid.size() && vis[r+1][c]==-1){
                    vis[r+1][c]=0;
                    q.push({r+1 , c});
                }
                if(c-1 >=0 && vis[r][c-1]==-1){
                    vis[r][c-1]=0;
                    q.push({r , c-1});
                }
                if(c+1 < grid[0].size() && vis[r][c+1]==-1){
                    vis[r][c+1]=0;
                    q.push({r , c+1});
                }
                
            }
        }
        
        return count;
        
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n , vector<int>(m , -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=0;
                }
            }
        }
        int x = bfs(grid, q, vis)-1;
        if(x==0) return -1;
        return x;
    }
};