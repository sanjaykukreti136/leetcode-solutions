class Solution {
public:
    
    int check(vector<int>&v,  int idx, int m , vector<vector<int>>&dp){
        if(idx >= v.size()) return 0;
        int sum = 0 ;
        if(dp[idx][m]!=-1) return dp[idx][m];
        int ans = INT_MIN;
        for(int j=0;j<2*m;j++)
        {
            if(idx+j < v.size()){
                sum+=v[idx+j];
            }
           ans =max(ans ,  sum - check(v , idx+j+1 , max( m , j+1 ) , dp ));
        }        
        return dp[idx][m] = ans;
    }
    
    int stoneGameII(vector<int>& v) {
        
        int n = v.size();
        int m = n*n;
        vector<vector<int>>dp(101 , vector<int>(201 , -1));
        int ans= check(v , 0 , 1 , dp);
        int s=0;
        for(auto i : v) s+=i;
        return (s + ans)/2;
    }
};