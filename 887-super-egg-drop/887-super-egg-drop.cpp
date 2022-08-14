class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1 , vector<int>(n+1, 0));
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(i == 1){
                    dp[i][j] = j;
                }
                else if(j == 1){
                    dp[i][j] = 1;
                }
                else{
                    int l = 1, r = j, temp = 0, ans = INT_MAX;
                 while(l <= r) {
                    int mid = (l + r)/2;
                    int left = dp[i-1][mid-1]; 
                    int right = dp[i][j-mid];  
                    temp = 1 + max(left,right);         
                    if(left < right) l = mid+1;                       
                    else r = mid-1;
                    ans = min(ans,temp);               
                 }
                 dp[i][j]=ans;
                }
            }
        }
        return dp[k][n];
    }
};