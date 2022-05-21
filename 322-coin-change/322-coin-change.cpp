class Solution {
public:
    int coinChange(vector<int>& coins, int t) {
        vector<int>dp(t+1, t+1);
        dp[0]= 0;
        for(int i=1;i<=t;i++){
            for(auto j : coins){
                if(i>=j){
                    dp[i] = min(dp[i], dp[i-j]+1);
                }
            }
        }
        return (dp[t]>t)?-1:dp[t];
    }
};