class Solution {
public:
    
    
    int check(vector<int>&v , int idx , int buy , vector<vector<int>>&dp){
        
        if(idx >= v.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy == 0){
            
            return dp[idx][buy] =   max( -v[idx] + check(v , idx+1 , 1,dp) , check(v,  idx+1 , 0,dp)  );
            
        }
        
        return dp[idx][buy] =  max( v[idx] + check(v , idx+2 , 0,dp) , check(v, idx+1 , 1,dp) );
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,  vector<int>(2  , -1));
        
        return check(prices , 0 , 0 , dp);
    }
};