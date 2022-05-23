class Solution {
public:
    int countSubstrings(string s) {
        int i,n=s.length(),count=0,j;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                dp[i-1][i]=1;
            }
        }
        for(j=2;j<n;j++)
        {
            for(i=0;i<j-1;i++)
            {
                if(dp[i+1][j-1]&&s[i]==s[j])
                {
                    dp[i][j]=1;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dp[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};