class Solution {
public:
    int dp[500001];
    
    int check(vector<int>&v, int idx){
        if(idx>=v.size()) return 0;
        int ans =INT_MIN;
        if(dp[idx]!=-1) return dp[idx]; 
        ans = max( ans , v[idx] - check(v, idx+1) );
        if(idx+1 < v.size()){
            ans = max(ans , v[idx] + v[idx+1] - check(v, idx+2));
        }
        if(idx+2 < v.size()){
            ans = max(ans , v[idx]+v[idx+1]+v[idx+2] - check(v, idx+3));
        }
        
        return dp[idx] = ans;
        
    }
    
    string stoneGameIII(vector<int>& v) {
        memset(dp , -1, sizeof(dp));
        int ans = check(v, 0 );
        if(ans > 0) return "Alice";
        else if(ans < 0) return "Bob";
        return "Tie";
    }
};