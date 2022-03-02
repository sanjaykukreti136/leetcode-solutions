class Solution {
public:
    
   string check(string s, int n ){
        
        string ans = "";
        int carry = 0;
        for(int i = s.size()-1;i>=0;i--){
            int val = (n*(s[i]-'0') + carry);
            
            if(val > 9){
                carry = val/10;
                val = val%10;
            }else{
                carry = 0;
            }
            ans.push_back((val+ '0'));
        }
        
        if(carry > 0){
            ans.push_back((carry+'0'));
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
    string add(string s , string y){
        int i = s.size()-1 , j = y.size()-1;
        int carry = 0;
        string res = "";
        while(i>=0 && j>=0){
            int a = (y[j]-'0') + (s[i]-'0') + carry;
            if(a > 9){
                carry =a/10;
                a = a%10;
            }else{
                carry = 0;
            }
            i--;
            j--;
            res.push_back(a+'0');
        }
        
        while(j>=0){
            int a = (y[j]-'0')  + carry;
            if(a > 9){
                carry =a/10;
                a = a%10;
            }else{
                carry = 0;
            }
            j--;
            res.push_back(a+'0');
        }
        
        while(i>=0){
            int a = (s[i]-'0') + carry;
            if(a > 9){
                carry =a/10;
                a = a%10;
            }else{
                carry = 0;
            }
            i--;
            res.push_back(a+'0');
        }
        
        if(carry > 0){
            res.push_back(carry+'0');
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    string multiply(string s1, string s2) {
        
        reverse(s2.begin(), s2.end());
        // int res = 0;
        string res = "";
        for(int i=0;i<s2.size();i++){
           string ans =  check(s1 , s2[i]-'0');
           int x = i;
            while(x--){
                ans+='0';
            }

           res =  add(res , ans);
            cout<<ans<<" - "<<res<<"\n";
        }
        int c = 0;
        // if(stoi(res)==0) return "0";
        for(int i=0;i<res.size();i++) {
            if(res[i]=='0') c++;
        }
        if(c==res.size()) return "0";
        return (res);
    }
};