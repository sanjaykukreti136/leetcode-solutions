class Solution {
public:
    
    int check(int idx , vector<int>&arr , int k , vector<int>&dp ){
        if(idx >= arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int s = arr[idx];
        int v = arr[idx];
        for(int i=idx;i<idx+k && i<arr.size();i++){
            v = max(v , arr[i]);
            s = max(s , v*(i-idx+1) + check(i+1 , arr , k  , dp) );
        }
        return dp[idx] = s;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n , -1);
        return check(0 , arr  , k  , dp);
    }
};