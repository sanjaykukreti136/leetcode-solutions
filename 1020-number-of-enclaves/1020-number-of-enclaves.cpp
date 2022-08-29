class Solution {
public:
    
    int check(int i , int j , vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return 0;
        grid[i][j] = 0;
        return 1 + check(i-1,j,grid)+check(i+1,j,grid)+check(i,j-1,grid)+check(i,j+1,grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
          int totalone = 0;
        for(auto i : grid){
            for(auto j : i){
                if(j==1) totalone++;
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1 ){
                    totalone-=check(i,j , grid);
                }
            }
        }
        return totalone;
    }
};