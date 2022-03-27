class Solution {
public:
    int dp[1001][2001];
    
    int check(vector<vector<int>>&piles , int idx , int sidx , int k , int x){
        if(idx >= piles.size()) return 0;        
        // if(piles[idx].size()<=sidx) return 0;
        if(x>=k) return 0;
        
        if(dp[idx][x]!=-1 ) return dp[idx][x];
        
        
        
        int ans = 0;
        int s=0;
        for(int i=0;i<piles[idx].size();i++){
            if(x+i+1>k) break;
            s+=piles[idx][i];
            ans = max(ans ,  check(piles, idx+1 , sidx , k , x+i+1) + s );
        }
        
        ans = max(ans , check(piles , idx+1 , 0 , k , x));
        
        
        return dp[idx][x] =   ans;
        
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp , -1 , sizeof(dp));
        return check(piles , 0 , 0 , k , 0);
    }
};