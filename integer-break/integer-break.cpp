class Solution {
public:
    int integerBreak(int n) {
        // return 5;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        // dp[2]=1;
        // dp[3]=2;
        for(int i=2;i<=n;i++){
            dp[i] = 0;
            for(int j=1;j<i;j++){
                dp[i] = max(dp[i], j*(max(dp[i-j], i-j)) );
            }
        }
        return dp[n];
        
    }
};