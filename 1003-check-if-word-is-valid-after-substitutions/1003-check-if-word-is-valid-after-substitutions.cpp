class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(auto i : s){
            
            if(st.empty() || i=='a' || i=='b'){
                st.push(i);
            }
            else{
                if(st.size()>=2){
                char a = st.top();
                st.pop();
                char b = st.top();
                st.pop();
                if(a=='b' && b=='a'){
                    
                }else{
                    st.push(b);
                    st.push(a);
                    st.push(i);
                }
                }else{
                    st.push(i);
                }
            }
            
        }
        return st.empty();
        
    }
};