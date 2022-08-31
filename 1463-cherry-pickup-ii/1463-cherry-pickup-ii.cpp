class Solution {
public:
    int dp[71][71][71];
    int check(vector<vector<int>>&grid, int r1 , int c1 , int r2 ,int c2 ){
        if(r1<0 || r2<0 || c1<0||c2<0 || r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size()|| c2>=grid[0].size() ) return INT_MIN;
        
        
        if(r1==grid.size()-1){
            if(r1==r2 && c1==c2) return grid[r1][c1];
            return   grid[r1][c1]+grid[r2][c2];
        }
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2]; 
        int ch = 0;
        if(r1==r2 && c1==c2){
            ch+=grid[r1][c1];
        }
        else{
            ch+=grid[r1][c1] + grid[r2][c2];   
        }
        
        int a = check(grid , r1+1,c1-1,r2+1,c2-1);
        int b = check(grid,r1+1,c1,r2+1,c2);
        int c = check(grid,r1+1,c1+1,r2+1,c2+1);
        int d = check(grid,r1+1,c1-1, r2+1,c2);
        int e = check(grid,r1+1,c1-1,r2+1,c2+1);
        int f = check(grid,r1+1,c1,r2+1,c2-1);
        int g = check(grid,r1+1,c1,r2+1,c2+1);
        int h = check(grid,r1+1,c1+1,r2+1,c2-1);
        int i = check(grid, r1+1,c1+1,r2+1,c2);
        
        int z = max(a,max(b,max(c,max(d,max(e,max(f,max(g,max(h,i))))))));
        ch+= z==INT_MIN ? 0 : z;
        return dp[r1][c1][c2] =  ch;
        
        
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        return check(grid , 0 , 0 , 0 , grid[0].size()-1);
    }
};