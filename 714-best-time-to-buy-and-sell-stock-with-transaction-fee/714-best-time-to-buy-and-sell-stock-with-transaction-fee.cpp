class Solution {
public:
    
    
        int dp[50001][2];
    int check(vector<int>&prices , int idx , int type , int fee){
        
        if(idx >= prices.size()) return 0; 
        if(dp[idx][type]!=-1) return dp[idx][type];
        if(type == 0){
            
            return dp[idx][type] = max( check(prices , idx+1 , 1 ,fee) - prices[idx]-fee , check(prices , idx+1 , type,fee)   );
            
        }
        else{
            return dp[idx][type] = max( check(prices , idx+1, 0,fee) + prices[idx] , check(prices , idx+1, type,fee) );
        }
        
    }
    
    int maxProfit(vector<int>& prices , int fee) {
        memset(dp , -1, sizeof(dp));
       return check(prices , 0 , 0  , fee);   
    }
};