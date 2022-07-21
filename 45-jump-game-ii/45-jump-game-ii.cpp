class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // int dp[n] = {0};
        vector<int>dp(n,0);
        for(int i=n-2;i>=0;i--){
            int jump = nums[i];
            int j = 1;
            int res = INT_MAX;
            for(int j=1;j<=jump && (i+j)<n;j++){
                res = min(res , dp[i+j]);
            }
            dp[i] = res==INT_MAX ? INT_MAX : res+1;
        }
        return dp[0];
        
    }
};