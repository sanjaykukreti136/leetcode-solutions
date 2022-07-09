class Solution {
public:
       map<int,int>dp;
   long calc(long n)
    {        
        if(n==1)
            return dp[n];
       if(dp[n]==NULL)
       {
        if(n%2==0)
        dp[n]=calc(n/2)+1;
        else            
        dp[n]=min(calc(n-1),calc(n+1))+1;  
       }       
        return dp[n];
    }
    int integerReplacement(int n) {
       return calc((long)n);
    }
};