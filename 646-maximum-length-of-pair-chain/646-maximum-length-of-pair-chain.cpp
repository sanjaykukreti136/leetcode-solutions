class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int>dp(n+1 , 0);
        
        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i] , 1 + dp[j]);
                }
                
            }
        }
        return dp[n-1];
        
        
    }
};