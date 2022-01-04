class Solution {
public:
    
    string check(string a ,string s){
        int n = s.length();
        int c = 0;
        int ans = 0;
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }else if(s[i-1]==a[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(dp[i][j] > ans &&  (i-dp[i][j] == n-j)){
                        c = i;
                        ans = dp[i][j];
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        cout<<ans<<" - "<<c<<"\n";
        string res= "";
        c-=ans;
        if(c<0) return "";
        int k=0;
        while(k<ans){
            res+=s[c++];
            k++;
        }
        return res;
    }
    
    string longestPalindrome(string s) {
        string a = s;
         reverse(s.begin(), s.end());
        return check(a, s);
    }
};