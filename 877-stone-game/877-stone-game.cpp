class Solution {
public:
    bool stoneGame(vector<int>& v) {
        int n = v.size();
        int dp[n][n];
        for(int g=0;g<n;g++){
            for(int i=0,j=g; j<n;i++,j++){
                if(g==0){
                    dp[i][j] = v[i];
                }
                else if(g == 1){
                    dp[i][j] = max(v[i] , v[j]);
                }
                else{
                    int val1 = v[i] + min(dp[i+2][j] , dp[i+1][j-1]);
                    int val2 = v[j] + min(dp[i+1][j-1], dp[i][j-2]);
                    dp[i][j] = max(val1, val2);
                }
            }
        }
        
        int val = dp[0][n-1];
        int s = 0;
        for(auto i : v) s+=i;
        s  = s-=val;
        return val>s;
        
    }
};