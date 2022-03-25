class Solution {
public:
    int dp[101][51][51];
    int check(vector<vector<int>>& costs , int idx , int a , int b ){
        if(idx == costs.size()) return 0;
        if(dp[idx][a][b]!=-1) return dp[idx][a][b];
        int res1 = INT_MAX , res2 = INT_MAX;
        
        if(a > 0){
            res1 = check(costs , idx+1 , a-1, b) + costs[idx][0];
        }
        if(b>0){
            res2 = check(costs , idx+1 , a , b-1) + costs[idx][1];
        }
        return dp[idx][a][b] =  min(res1 , res2);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
       int apart = costs.size()/2;
        memset(dp , -1, sizeof(dp));
       return  check(costs , 0 , apart , apart );
    }
};