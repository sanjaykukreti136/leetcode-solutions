class Solution {
public:
    
    int lcs(string a , string b){
        int n = a.size(), m = b.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else{
                    if(a[i-1]==b[j-1]){
                        dp[i][j] = dp[i-1][j-1]+(a[i-1]);
                    }else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n][m];
    }
    
    int minimumDeleteSum(string s1, string s2) {
        long a = 0 , b =0;
        for(auto i : s1){
            a+=(i);
        }
        for(auto i : s2){
            b+=(i);
        }
        
        int s = lcs(s1 , s2);
        
        
        return (a+b)-(2*s);
        
    }
};