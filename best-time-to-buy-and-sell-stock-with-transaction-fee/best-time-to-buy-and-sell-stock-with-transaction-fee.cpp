class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int loan =0;
        int profit = 0;
        int prevloan =-prices[0];
        for(int i=1;i<prices.size();i++){
            loan = max(prevloan , (-1)*(prices[i]-profit) );
            profit = max(profit , prices[i]+prevloan-fee);
            prevloan = loan;
        }
        return profit;
    }
};