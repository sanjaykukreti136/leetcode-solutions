class Solution {
public:
    int dp[100005][2][3];
    long mod = 1e9+7;
    
    int check(int n, int a, int l){
        if(a>1) return 0;
        if(l>2) return  0;
        if(n==0) return 1;
        if(dp[n][a][l]!=-1) return dp[n][a][l];
        
        return dp[n][a][l]= (check(n-1,a+1, 0)%mod+check(n-1,a,0)%mod+check(n-1 , a,l+1)%mod)%mod;
        
    }
    
    int checkRecord(int n) {
        memset(dp , -1 , sizeof(dp));
        return check(n , 0 , 0);
    }
};