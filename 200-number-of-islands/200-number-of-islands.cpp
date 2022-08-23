class Solution {
public:
    
    void check(int r , int c , vector<vector<char>>&grid , vector<vector<bool>>&vis){
        
        vis[r][c] = true;
        
        grid[r][c] = '.';
        
        // top
        if(r-1>=0 && vis[r-1][c]==false && grid[r-1][c]=='1'){
            check(r-1 , c , grid , vis);
        }
        // bottom
        if(r+1<grid.size() && vis[r+1][c]==false && grid[r+1][c]=='1'){
            check(r+1 , c , grid , vis);
        }
        
        // left
        if(c-1>=0 && vis[r][c-1]==false && grid[r][c-1]=='1'){
            check(r , c-1 , grid , vis);
        }
        // right
        if(c+1<grid[0].size() && vis[r][c+1]==false && grid[r][c+1]=='1'){
            check(r , c+1 , grid , vis);
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n =  grid.size() , m = grid[0].size();
        vector<vector<bool>>visited(n , vector<bool>(m , false));
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
                
//                 if(i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1 || grid[i][j]=='1'){
                    
//                     check(i , j , grid , visited );
                    
//                 }
                
//             }
//         }
        int c = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    // cout<<i<<" "<<j<<"\n";
                    c++;
                    check(i , j , grid , visited);
                }
            }
        }
        
        return c; 
        
    }
};



