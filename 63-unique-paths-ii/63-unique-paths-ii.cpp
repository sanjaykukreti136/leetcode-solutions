class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        vector<vector<long long >>dp(n , vector<long long >(m , 0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                 if(v[i][j]==1){
                     dp[i][j] = 0;
                     continue;
                 }
                if(i==n-1 && j==m-1 ){
                    dp[i][j] = 1;
                   
                }
                else if(i==n-1 ){
                    dp[i][j] = dp[i][j+1];
                    if(v[i][j]==1) dp[i][j] =0;
                }
                else if(j==m-1){
                    dp[i][j] = dp[i+1][j];
                    // if(v[i][j]==1) dp[i][j] =0;
                }
                else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    // if(v[i][j]==1) dp[i][j] =0;
                }
            }
        }
        return dp[0][0];
    }
};