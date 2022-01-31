class Solution {
public:
    long long modulo = 1e9+7;
    int countOrders(int n) {
        int dp[n+1];
        dp[1] =1;
        if(n==1) return 1;
        dp[2] = 6;
        if(n==1 || n==2) return dp[n];
        for(int i=3;i<=n;i++){
            int space = (i-1)*2+1;
            dp[i] = (((space%modulo + ((space*(space-1))/2)%modulo)%modulo)*dp[i-1])%modulo;
        }
        return dp[n];
    }
};