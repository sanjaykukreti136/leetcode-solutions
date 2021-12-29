class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int loan =0;
        int prevloan = -prices[0];
        int profit =0;
        int prevprofit = 0;
        int cooldown = 0;
        for(int i=1;i<prices.size();i++){
            loan = max(prevloan , cooldown - prices[i] );
            profit = max( prevprofit , prices[i] + prevloan );
            cooldown = max(cooldown  , prevprofit);
            prevprofit = profit;
            prevloan = loan;
        }
        return profit;
    }
};