class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char sign = '+';
        char ch;
        for(int i=0;i<s.length();i++){
            ch = s[i];
            if(isdigit(ch)){
                int n = 0;
                while(i<s.length() && isdigit(ch) ){
                    n =n*10 + (ch-'0');
                    i++;
                    ch = s[i];
                }
                i--;
                if(sign == '+'){
                    st.push(n);
                }
                else if(sign =='-'){
                    st.push(-n);
                }
                else if(sign == '*'){
                    int b = st.top();
                    st.pop();
                    st.push(n*b);
                }
                else{
                    int b = st.top();
                    st.pop();
                    st.push(b/n);
                }
                
            }
            else if(!isspace(s[i])){
                sign = s[i];
            }
        }
        
        int ans =0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
            
    }
};