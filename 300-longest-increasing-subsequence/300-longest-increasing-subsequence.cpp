class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = 1;
        int ans=  1;
        for(int i =1;i<nums.size();i++){
            int maxv = 0;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    maxv= max(maxv , dp[j]);
                }
            }
            dp[i] = maxv+1;
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};