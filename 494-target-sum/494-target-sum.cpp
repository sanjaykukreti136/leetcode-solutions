class Solution {
public:
    
     // int dp[1002][22];
    map<pair<int,int>,int>m;
    int helper(vector<int>&nums, int n,int target)
    {
        if(n==0 and target==0) return 1;
        if(n==0) return 0;
        
        // if(dp[n][target]!=-1) return dp[n][target];
        // if(m.find({n , target})!=m.end()) return m[{n , target}];
        
        int cnt1=0,cnt2=0;
        
        cnt1+=helper(nums, n-1, target+nums[n-1]);
        cnt2+=helper(nums, n-1, target-nums[n-1]);
        
        return cnt1+ cnt2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        if(!n) return 0;
        // memset(dp,-1,sizeof(dp));
        return helper(nums, n, target);
    }
};