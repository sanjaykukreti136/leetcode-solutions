class Solution {
public:
    int minFlips(string s) {
        vector<vector<int>>dp(2, vector<int>(2 , 0));
        for(int i=0;i<s.size();i++){
            dp[s[i]-'0'][i%2]++;
        }
        // dp[0][0] /// even pos , 0 count
//        dp[0][1] // odd pos  , 1 count
//         dp[1][0] odd pos , 0 count
//         dp[1][1] odd pos , 1 count
        int res = dp[0][1] + dp[1][0];
        res  = min(res , dp[0][0] + dp[1][1]);
        int n  = s.size();
        for(int i=0;i<s.size();i++){
            dp[s[i]-'0'][i%2]--;
            dp[s[i]-'0'][(n+i)%2]++;
            res = min(res, dp[0][0] + dp[1][1]);
            res = min(res , dp[1][0] + dp[0][1]);
        }
        return res;
    }
};