class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int sell =1;
        int sum=0;
        while(sell < prices.size()){
            if(prices[sell] > prices[buy] ){
                sum =max(sum, prices[sell] - prices[buy]);
                
            }
            else if(prices[buy] > prices[sell]){
                buy = sell;
               
            }
            sell+=1;
            
        }
        return sum-0;
    }
};