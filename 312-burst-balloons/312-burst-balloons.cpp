class Solution {
public:
    

    int dp[302][302];
    int solve(vector<int>& nums, int left, int right){
        if (left>=right){
            return 0;
        }
        if (dp[left][right]!=-1){
            return dp[left][right];
        }
        int ans=INT_MIN;
        for (int k=left;k<right;k++){
            int temp=solve(nums,left,k)+solve(nums,k+1,right)+nums[left-1]*nums[k]*nums[right];
            ans=max(ans,temp);
        }
        return dp[left][right]= ans;
        
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        memset(dp,-1,sizeof(dp));
        return solve(nums,1,nums.size()-1);
    }
};