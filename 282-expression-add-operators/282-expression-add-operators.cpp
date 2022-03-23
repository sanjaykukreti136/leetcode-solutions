class Solution {
public:
    
    void check(vector<string>&res , string s, string curr ,  int pos , long total , long prev , char op , int ta){
        if(pos==s.size() && total == ta){
            res.push_back(curr);
            return ; 
        }
        else{
            
            for(int i=pos+1;i<=s.size();i++){
                string t = s.substr(pos, i-pos);
                long a = stol(t);
                if(to_string(a).size()!=t.size()) continue;
                
                check(res , s , curr+'+'+t , i, total+a , a , '+' , ta);
                check(res ,s , curr+'-'+t, i , total-a,a , '-', ta);
                check(res,s,curr+'*'+t,i, (op=='-'? total+prev-(prev*a) : (op=='+')?total-prev+(prev*a) : prev*a  ),prev*a,op,ta );
                
            }
            
        }
        
        
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string>res;
        
        for(int i=1;i<=num.size();i++){
            string s=  num.substr(0 , i);
            long a = stol(s);
            if(to_string(a).size()!=s.size()) continue;
            
            check(res , num , s , i , a , a , '.' , target );
            
        }
        return res;
    }
};