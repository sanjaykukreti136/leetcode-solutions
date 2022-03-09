class Solution {
public:
    int findLength(vector<int>& s1, vector<int>& s2) {
        int n = s1.size(), m = s2.size();
          int dp[n+1][m+1];
        int ans = 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else{
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=  dp[i-1][j-1]+1;
                    ans = max(ans , dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
                }
            }
        }
        return ans;
    }
};