class Solution {
public:
    unordered_map<int , bool>dp;
    bool check(string s , unordered_set<string>&st , int idx){
        if(idx == s.size()) return true;
        if(dp.find(idx)!=dp.end()) return dp[idx];
        for(int i = idx ; i<s.size();i++){
            
            if(st.find(s.substr(idx , i-idx+1))!=st.end() && check(s ,st , i+1) ){
               return  dp[idx] = true;
            }
            
        }
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // memset(dp , -1  , sizeof(dp) );
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        return check(s , st , 0);
    }
};