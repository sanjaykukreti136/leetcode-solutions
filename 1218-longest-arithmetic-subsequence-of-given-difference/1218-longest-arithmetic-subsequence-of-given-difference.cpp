class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
         int n=arr.size();
        
        int dp[2000002];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=n-1;i>=0;i--){
            dp[arr[i]+100000]=1+dp[arr[i]+d+100000];
            ans=max(ans,dp[arr[i]+100000]);
        }
        
        return ans;
    }
};