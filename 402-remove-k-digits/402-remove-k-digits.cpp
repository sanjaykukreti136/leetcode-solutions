class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>s;
        for(int i=0;i<num.size();i++){
            int val = num[i]-'0';
            while(!s.empty() && s.top() > val && k ){
                s.pop();
                k-=1;
            }
            
            if(!s.empty() || val!=0){
                s.push(val);
            }
            
        }
        
        
        while(!s.empty() && k){
            s.pop();
            k--;
        }
        
        if(s.empty()) return "0";
        
        string ans="";
        while(!s.empty()){
            ans = to_string(s.top())+ans;
            s.pop();
        }
        return ans;
        
    }
};