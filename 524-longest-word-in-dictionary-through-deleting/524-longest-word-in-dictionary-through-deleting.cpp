class Solution {
public:
    
    string check(string a , string b){
        
        int i=0, j = 0;
        
        while(i<a.size() && j<b.size() ){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i==a.size()) return a;
        return "";
        
    }
    
    string findLongestWord(string s, vector<string>& v) {
        sort(v.begin(), v.end());
        string res = "";
        
        for(int i=v.size()-1;i>=0;i--){
            
            string t = check(v[i] , s);
            if(t.size() > res.size()){
                res = t;
            }else if(t.size() == res.size()){
                if(t<res){
                    res  = t;
                }
            }
            
        }
        return res;
    }
};