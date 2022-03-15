class Solution {
public:
    string minRemoveToMakeValid(string s) {
        map<int, int>m;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                
                if(st.empty() || s[i]=='('){
                    st.push(i);
                }else if(s[i]==')' && s[st.top()]=='('){
                    st.pop();
                }else{
                    st.push(i);
                }
                
            }
        }
        
        while(!st.empty()){
            m[st.top()]= 1;
            st.pop();
        }
        string ans ="";
        for(int i=0;i<s.size();i++){
            if(m.find(i)==m.end()) ans.push_back(s[i]);
        }
        return ans;
        
    }
};