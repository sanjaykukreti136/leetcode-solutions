class Solution {
public:
    
    
    //// https://leetcode.com/problems/count-numbers-with-unique-digits/discuss/83052/Clear-c%2B%2B-explanation-of-combinatorics-using-DP-method
    
    
     /// imp link
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(n+1, 0 );
        dp[0] = 1;
        if(n==0) return 1;
        dp[1] = 10;
        for(int i=2;i<=n;i++){
            dp[i] = 9;
            int k = 9;
            int j = 1;
            while(j < i){
                dp[i]*=k;
                j++;
                k--;
            }
            dp[i]+=dp[i-1];
        }
        return dp[n];
    }
};