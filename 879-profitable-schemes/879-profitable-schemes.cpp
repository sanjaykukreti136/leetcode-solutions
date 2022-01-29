class Solution {
public:
    int dp[101][101][101];
    long long mod = 1e9+7;
    int check(int total_members , int total_profit , int index , vector<int>&group , vector<int>&profit ){
        if(total_members<0) return 0;
        if(index == -1){
            if(total_profit==0) return 1; /// we have generated minimum target 
            return 0;
        }
        
        if(dp[total_members][total_profit][index]!=-1) return dp[total_members][total_profit][index];
        
        int ans = 0;
        //since we have to calculate total ways ;
        ans+= check(total_members , total_profit , index-1 , group , profit)%mod;
        ans+= check(total_members-group[index] , max(0,total_profit-profit[index]), index-1, group , profit)%mod;
        
        return dp[total_members][total_profit][index] = ans%mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp , -1 , sizeof(dp));
        return check(n , minProfit, profit.size()-1 , group , profit );
    }
};