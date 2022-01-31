class Solution {
public:
    int dp[5001][301];
    
    int check(int t,  vector<int>&v, int idx){
        if(t == 0){
            return 1;
        }
        if(idx == v.size()){
            return 0;
        }
        if(dp[t][idx]!=-1) return dp[t][idx];
        if(t>=v[idx]){
            return dp[t][idx] = ( check(t-v[idx] , v, idx) + check(t , v, idx+1) );
        }else{
            return dp[t][idx] = check(t , v, idx+1);
        }
        
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp , -1, sizeof(dp));
        return check(amount , coins , 0);
        
    }
};