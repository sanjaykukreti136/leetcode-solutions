class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int>>dp(n ,vector<int>(m, 0));
        vector<vector<int>>dp1(n ,vector<int>(m, 0));
        vector<vector<int>>dp2(n ,vector<int>(m, 0));
        for(int i= n-1;i>=0;i--){
            int s = 0;
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1') s+=1;
                else s = 0;
                dp1[i][j] = s;
            }
        }
        
        for(int j=m-1;j>=0;j--){
            int s = 0;
            for(int i=n-1;i>=0;i--){
                 if(matrix[i][j]=='1') s+=1;
                else s = 0;
                dp2[i][j] = s;
            }
        }
        int res = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 || j==m-1){
                    dp[i][j] = matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='1'){
                        
                        dp[i][j] = min( dp1[i][j] , min(dp2[i][j] , dp[i+1][j+1]+1) );
                    }else{
                        dp[i][j] = 0;
                    }
                }
                res = max(res , dp[i][j]);
            }
        }
        
        return res*res;
        
        
    }
};