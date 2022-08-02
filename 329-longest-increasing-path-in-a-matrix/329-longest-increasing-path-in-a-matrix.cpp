class Solution {
public:
    int dp[301][301];
    
    int check(int r ,int c, vector<vector<int>>&v , int val){
        // cout<<val<<" ";
        if(dp[r][c]!=-1) return dp[r][c];
        
        int ans = 0;
        if(r-1>=0 && v[r-1][c]>v[r][c] ){
            ans = max(ans , check(r-1,c,v,dp[r][c]) );
        }
        if(r+1 < v.size() && v[r+1][c]>v[r][c]){
            ans = max(ans , check(r+1,c,v,dp[r][c]) );
        }
        if(c+1 < v[0].size() && v[r][c+1]>v[r][c] ){
            ans = max(ans , check(r,c+1,v,dp[r][c]) );
        }
        if(c-1>=0 && v[r][c-1] > v[r][c] ){
            ans = max(ans , check(r,c-1,v,dp[r][c]) );   
        }
        
        return dp[r][c] =   ans+1;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp , -1, sizeof(dp));
        int n = matrix.size() , m = matrix[0].size();
        
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res = max(res , check(i,j,matrix,-1));
                // cout<<"\n";
            }
        }
        return res;
    }
};