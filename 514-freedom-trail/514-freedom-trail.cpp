class Solution {
public:
    int dp[101][101];
    int helper(string ring,string key,int i,int j){
        int n = ring.length();
        int m = key.length();
        if(dp[i][j]!=-1)return dp[i][j];
        if(j==key.length())return 0;
        int clk = 0;
        int anticlk = 0;
        int answer = 0;
        int temp1 = i;
        while(ring[temp1]!=key[j]){
            temp1 = (temp1+1)%n;
            clk++;
        }
        int temp2 = i;
        while(ring[temp2]!=key[j]){
            temp2 = (temp2-1+n)%n;
            anticlk++;
        }
        answer = min(clk+1+helper(ring,key,temp1,j+1),anticlk+1+helper(ring,key,temp2,j+1));
        return dp[i][j] = answer;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length();
        memset(dp,-1,sizeof dp);
        return helper(ring,key,0,0);
    }
};