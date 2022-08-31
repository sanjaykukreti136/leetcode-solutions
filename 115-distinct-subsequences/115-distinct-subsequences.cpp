class Solution {
public:
    int dp[1001][1001];
    int check(string s , string t , int  n , int m){
        
        if(m==-1) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]){
            return dp[n][m] = check(s,t,n-1,m-1) + check(s,t,n-1,m);
        }else{
            return dp[n][m] =  check(s,t,n-1,m);
        }
    }
    
    int numDistinct(string s, string t) {
        memset(dp ,-1,sizeof(dp));
        return check(s , t, s.size()-1, t.size()-1);
    }
};