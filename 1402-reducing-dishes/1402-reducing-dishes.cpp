class Solution {
public:
    int dp[501][501];
    int check(vector<int>&v, int idx , int t){
        if(idx == v.size()) return 0;
        if(dp[idx][t]!=-1) return dp[idx][t];
        
        return dp[idx][t]=  max( check(v, idx+1 , t+1) + v[idx]*t , check(v, idx+1 , t) );
        
    }
    
    int maxSatisfaction(vector<int>& v) {
        memset(dp , -1, sizeof(dp));
        sort(v.begin(), v.end());
        return check(v , 0  , 1);
    }
};