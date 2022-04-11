class Solution {
public:
    
    bool check(string s, map<string,int>&m , int c){
        if(s.size()==0 && c>1) return true;
        if(s.size()==0 && c==1) return false;
        
        int i =0;
        string temp  = "";
        while(i<s.size()){
            temp.push_back(s[i]);
            string res = s.substr(i+1);
            if(m.find(temp)!=m.end()){
                if(check(res,m , c+1)){
                    return true;
                }
            }
            i++;
        }
        
        return false;
        
    }
    
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        map<string,int>m;
        vector<string>ans;
        for(auto i : words){
            m[i]++;
        }
        
        for(auto i : words){
            if(check(i , m , 0)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};