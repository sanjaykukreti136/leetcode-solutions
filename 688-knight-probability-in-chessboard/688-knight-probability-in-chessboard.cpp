class Solution {
public:
    double real = 0, all = 0 ;
    double dp[26][26][101];
    vector<vector<int>> dir={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    double check(int n , int k , int r , int c , int a , int b){
        if(r < 0 || r>=n || c<0 || c>=n) return 0;
        
        if(k==0){
            return 1;
        }
        
        if(dp[r][c][k]!=0.0) return dp[r][c][k];
      
        
        double rea = 0 ;
        for(auto i : dir){
            int x = i[0], y = i[1];
            int t=0;
            if(r+x>=0 && r+x<n && c+y>=0 && c+y<n){
                rea+=check(n , k-1 , r+x , c+y , a , b)/8.0;
            }

        }
        return  dp[r][c][k] =  rea;
    }
    
    double knightProbability(int n, int k, int row, int column) {
       memset(dp , 0.0 , sizeof(dp));
       return  check(n ,k , row , column , row , column);
    }
};