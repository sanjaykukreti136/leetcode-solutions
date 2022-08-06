class Solution {
public:
    int dp[201][10000]; 
    bool check(vector<int>&v, int idx , int t){
        
        if(t==0) return true;
        if(t<0 || idx>=v.size()) return false;
        if(dp[idx][t]!=-1) return dp[idx][t];
        bool ans = false;
        if(v[idx]<=t){
            ans = ans || check(v , idx+1 , t-v[idx]) ;
        }
        ans = ans || check(v , idx+1  , t);
        return dp[idx][t] =  ans;
        
    }
    
    bool canPartition(vector<int>& nums) {
        // return check(nums , idx , )
        int s = 0;
        memset(dp , -1 , sizeof(dp));
        for(auto i : nums) s+=i;
        if(s%2!=0) return false;
        
        return check(nums , 0 , s/2);
        
    }
};