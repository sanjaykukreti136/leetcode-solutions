class Solution {
public:
    vector<string>v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void check(string s, int idx , string asf, vector<string>&ans){
        if(idx==s.length()){
            ans.push_back(asf);
            return ;
        }
        
        string t = v[s[idx]-'0'];
        for(int i=0;i<t.length();i++){
            check(s , idx+1 , asf+t[i] , ans);
        }
        
    }
    vector<string> letterCombinations(string s) {
        
        vector<string>ans;
        if(s.length()==0) return ans;
        check(s , 0 , "", ans);
        return ans;
        
    }
};