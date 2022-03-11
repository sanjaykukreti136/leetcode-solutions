class Solution {
public:
    int dp[100006][5];
    
    int check(vector<int>&v, int idx  , int k , bool b){
        if(k==0){
            return 0;
        }
        
        if(idx == v.size()) return 0;
        
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        int ans = 0;
        int ans1 = check(v , idx+1, k , b);
        if(k%2==0){
            ans =   ( -v[idx] +  check(v, idx+1, k-1 , false) );
        }else{
            ans =   (v[idx] + check(v, idx+1, k-1 , true));
        }
        
        return dp[idx][k] = max(ans , ans1);
        
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return check(prices , 0 , 4 , false);
    }
};