class Solution {
public:
    
    void check(vector<vector<bool>>&vis , vector<vector<char>>&grid , int sr , int sc){
        
        
        queue<pair<int,int>>q;
        
        vis[sr][sc] = true;
        q.push({sr , sc  });
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r-1>=0 && vis[r-1][c]==false && grid[r-1][c] == '1' ){
                q.push({r-1 , c});
                vis[r-1][c] = true;
            }
            if(c-1>=0 && vis[r][c-1] == false && grid[r][c-1]=='1'){
                q.push({r , c-1});
                vis[r][c-1] = true;
            }
            if(c+1 < grid[0].size() && vis[r][c+1]==false && grid[r][c+1]=='1'){
                q.push({r,  c+1});
                vis[r][c+1] = true;
            }
            if(r+1 < grid.size()  && vis[r+1][c]==false && grid[r+1][c]=='1'){
                q.push({r+1 , c});
                vis[r+1][c] = true;
            }
            
        }
        
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m , false));
        int c = 0 ;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && grid[i][j]=='1'){
                    check(vis , grid , i , j);
                    c++;
                }
            }
        }
        
        return c;
        
    }
};