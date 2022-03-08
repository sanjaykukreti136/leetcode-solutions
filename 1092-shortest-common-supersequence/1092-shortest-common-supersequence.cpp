class Solution {
public:
      string longestCommonSubsequence(string a, string b) {
        string s=  "";
        int n = a.size(), m = b.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else{
                    if(a[i-1]==b[j-1]){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
          
          
         int r = n , c = m;
          while(r> 0 && c>0){
              if(a[r-1]==b[c-1]){
                  s.push_back(a[r-1]);
                  r-=1;
                  c-=1;
              }else{
                  if(dp[r-1][c] > dp[r][c-1]){
                      s.push_back(a[r-1]);
                      r-=1;
                  }else{
                      s.push_back(b[c-1]);
                      c-=1;
                  }
              }
          }
          while(r>0){
              s.push_back(a[r-1]);
              r--;
          }
            while(c>0){
              s.push_back(b[c-1]);
              c--;
          }
         reverse(s.begin(), s.end());
         return s;
    }
    string shortestCommonSupersequence(string str1, string str2) {
      return   longestCommonSubsequence(str1 , str2);
    }
};