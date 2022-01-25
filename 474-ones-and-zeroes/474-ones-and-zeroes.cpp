class Solution {
public:
    int ans  = 0;
    int count(string s){
        int  c= 0;
        for(auto i : s) if(i=='1') c++;
        return c;
    }
    int dp[601][101][101];
    int check(vector<string>&v , int idx , int m , int n ){
        if(idx == v.size() || m<0 || n<0){
            return 0;
        }
        if(m==0 && n==0) return 0;
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        
        int one  = count(v[idx]);
        int zero = v[idx].length()- one;
        if(m-zero>=0 && n-one>=0){
          return dp[idx][m][n] = max(check(v , idx+1 , m-zero , n-one)+1 , check(v, idx+1 , m , n) );
        }
        return dp[idx][m][n] = check(v, idx+1 , m , n );
     
       
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int x = strs.size();
        memset(dp  , -1 , sizeof(dp));
        return check(strs, 0 , m , n );
       
    }
};