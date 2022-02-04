class Solution {
public:
    int pickDate(vector<int>& days, int i, int type) {
        
        int goal = days[i] ;
        int ans = i ;
        
        if (type == 1) goal += 6 ;
        if (type == 2) goal += 29 ;
        
        while(days[ans] <= goal) {
            ans++ ;
            
            if (ans >= days.size()) {
                ans = days.size() ;
                break ;
            }
        }
        
        return ans ;
    }
    int check(vector<int>&days , int idx, int day , vector<int>&costs , vector<int>&dp){
        if(idx >= days.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
      
         return  dp[idx] = min( costs[0]+check(days , pickDate(days , idx, 0) , day , costs , dp) ,  min( costs[1]+check(days , pickDate(days, idx , 1) , day+6 , costs , dp) ,costs[2]+check(days , pickDate(days , idx, 2) , day+29 , costs , dp)  )       );
        
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>dp(366 , -1);
        return check(days , 0 , 0 , costs , dp );
    }
};