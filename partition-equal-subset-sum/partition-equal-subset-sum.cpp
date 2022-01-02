class Solution {
public:
    
    
    bool check(vector<int>v ,int idx , int sum , vector<vector<int>>&dp){
        if(idx == v.size()) return false;
        if(sum == 0) return true;
        bool ans = true;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        if(v[idx]<=sum){

            return dp[idx][sum] =  check(v, idx+1 , sum-v[idx], dp) || check(v, idx+1 , sum, dp);
        }else{
            return dp[idx][sum] =  check(v, idx+1 , sum , dp);
        }
    }
    
    bool canPartition(vector<int>& nums) {
        int sum =0;
        // if(su)
        for(auto i : nums){
            sum+=i;
        }
        if(sum%2!=0) return false; 
        sum = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(sum+1 , -1));        
        return check(nums, 0 , sum, dp);
        
    }
};