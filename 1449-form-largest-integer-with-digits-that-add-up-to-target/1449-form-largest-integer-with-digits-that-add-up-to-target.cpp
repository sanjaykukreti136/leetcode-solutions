class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n=cost.size();
        vector<vector<string>> dp(n+1,vector<string>(target+1,"-1"));
        return dfs(cost,0,target,dp);
    }
    string dfs(vector<int>& cost,int idx,int target,vector<vector<string>>& dp){
        if(target==0) return ""; //success
        if(target<0 || idx==cost.size()) return "0"; //failure 
        
        if(dp[idx][target]!="-1") return dp[idx][target];
        
        string includes=to_string(idx+1)+dfs(cost,0,target-cost[idx],dp);
        string excludes=dfs(cost,idx+1,target,dp);
        
        return dp[idx][target]=getBigger(includes,excludes);
    }
    string getBigger(string& s1,string& s2){
        string t="0";
        if (s1.find(t) != std::string::npos) return s2;
        if (s2.find(t) != std::string::npos) return s1;
        if(s1.length()>s2.length()) return s1;
        else return s2;
    }
};
// class Solution {
// public:
    
//     string check(vector<int>&cost , int idx , int target  , vector<vector<string>>&dp){
//         if(target == 0) return "";
//         if(idx == cost.size() || target < 0) return "0";
//         if(dp[idx][target]!="-1" ) return dp[idx][target];
//         string take_it = "", leave_it = "";
//         /// take it 
//         take_it = to_string(idx+1) + check(cost, 0 , target-cost[idx] , dp);
        
//         // leave it 
//         leave_it = check(cost , idx+1 , target, dp);
        
//         return dp[idx][target] = max_value(take_it , leave_it);
//     }
    
//     string largestNumber(vector<int>& cost, int target) {
//         int n = cost.size();
//         vector<vector<string>>dp(n+1 , vector<string>(target+1 , "-1"));
//         return check(cost , 0 , target , dp );
//     }
    
//     string max_value(string a, string b){
//         string t = "0";
//         if(a.find(t)!=string::npos) return b;
//         if(b.find(t)!=string::npos) return a;
//         return a.size() > b.size() ? a : b;
//     }
    
// };