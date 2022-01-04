class Solution {
public:
    
    int check(vector<vector<int>>&v, int idx , int k , vector<vector<int>>&dp){
        if(k==2) return 0;
        if(idx >= v.size()) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        vector<int>ans = { v[idx][1] , INT_MAX , INT_MAX };
        int nidx = upper_bound(begin(v), end(v) , ans) - begin(v);
        
        int indx = v[idx][2] + check(v , nidx  , k+1 , dp);
        int eidx = check(v , idx+1 , k , dp);
        
        return dp[idx][k] = max(indx , eidx);
    }
    
    int maxTwoEvents(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>>dp(n , vector<int>(2,-1));
        sort(v.begin() , v.end());
        
        return check(v , 0 , 0 , dp );
    }
};