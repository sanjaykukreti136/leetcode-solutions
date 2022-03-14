class Solution {
public:
    void check(string s , int n, vector<string>&v, vector<string>&ans, string rest){
        for(int i=1;i<=n;i++){
            string temp  = s.substr(0 ,i);
            
            if(find(v.begin(), v.end(), temp)!=v.end()){
                
                if(i==n){
                    rest+= temp;
                    ans.push_back(rest);
                    return ;
                }
                check(s.substr(i, n-i), n-i, v, ans, rest+temp+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        check(s, s.length(), wordDict , ans ,"");
        return ans;
    }
};