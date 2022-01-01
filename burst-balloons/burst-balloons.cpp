class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                
                int maxv = INT_MIN;
                for(int k=i;k<=j;k++){
                    int left = k==i?0: dp[i][k-1];
                    int right = k==j?0: dp[k+1][j];
                    int val  = nums[k];
                    if(i >0){
                        val*= nums[i-1];
                    }
                    if(j < n-1){
                        val*= nums[j+1];
                    }
                    if(val + left+right > maxv){
                        maxv = val + left + right;
                    }
                }
                dp[i][j] = maxv;
                
            }
        }
        return dp[0][n-1];
    }
};