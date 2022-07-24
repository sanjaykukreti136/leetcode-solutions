class Solution {
public:
    int countCollisions(string s) {
        stack<char>st;
        int c = 0;
        bool acc = false;
        for(int i=0;i<s.size();i++){
            if(st.empty() && acc && s[i]=='L'){
                c++;
                continue;
            }
            if(st.empty() ){
               if(s[i]!='L') st.push(s[i]);
            }else{
                
                if(st.top()=='L'){
                    
                }else if(st.top()=='S'){
                    
                    if(s[i]=='L') c++;
                    else if(s[i]=='R') {
                        st.push(s[i]);
                    }
                    
                }else{
                    int x = 0;
                    if(s[i]=='S' || s[i]=='L'){
                        while(!st.empty() && st.top()=='R'){
                            x++;
                            st.pop();
                        }
                        c+=x;
                        acc = true;
                        if(s[i]=='S') st.push(s[i]);
                        else c++;
                    }else{
                        st.push(s[i]);
                    }
                    
                }
                
            }
        }
        return c;
        
    }
};