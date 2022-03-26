class Solution {
public:
    int dp[1001][101][2];
    int helper(vector<int>&prices, int idx, int k,int buy)
    {
        if(idx==prices.size() or k<=0) return 0;
        if(dp[idx][k][buy]!=-1) return dp[idx][k][buy];
        int profit=0;
        if(buy)
        {
            int op1= helper(prices, idx+1, k,0)-prices[idx];
            int op2= helper(prices, idx+1, k, 1); // skip buy 
            profit = max(op1, op2);
        }
        else
        {
            int op1= helper(prices, idx+1, k-1,1) + prices[idx];
            int op2= helper(prices, idx+1, k,0);
            profit= max(op1,op2);
        }
        return dp[idx][k][buy] =   profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return helper(prices, 0,k,1);
    }
};