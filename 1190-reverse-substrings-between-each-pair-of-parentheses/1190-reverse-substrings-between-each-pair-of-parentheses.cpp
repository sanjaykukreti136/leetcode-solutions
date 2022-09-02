class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                queue<char>temp;
                while(st.top()!='('){
                    temp.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!temp.empty()){
                    st.push(temp.front());
                    temp.pop();
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};