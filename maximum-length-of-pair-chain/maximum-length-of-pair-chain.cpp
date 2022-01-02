class Solution {
public:
    int ans = 0;
    int check(vector<vector<int>>&v, int val , int c , int idx , vector<int>&dp){
        if(idx == v.size()){
            // ans = max(ans , c);
            return 0;
        }
        if(dp[idx]!=-1001) return dp[idx];
        int ans = 0;
        if(v[idx][0]>val){
           ans = 1+check(v , v[idx][1] , c+1 , idx+1 , dp); 
            
        }
       ans = max(ans ,  check(v , val , c , idx+1 , dp));
       return  dp[idx] = ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int>dp(n+1 , -1001);
        sort(pairs.begin(), pairs.end(), com);
        return check(pairs , -1001 , 0 , 0 ,dp);
        // return ans;
    }
    
private :
     static bool com(vector<int>&a, vector<int>&b){
         return a[1] < b[1] ;
     }
};