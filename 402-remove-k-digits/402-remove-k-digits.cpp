class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.length();i++){
            if(st.empty() ||  st.top()<=(num[i]) || k==0 ){
                st.push(num[i]);
            }else{
                while(k && !st.empty() && st.top()>num[i]){
                    st.pop();
                    k-=1;
                }
                st.push(num[i]);
            }
        }
        
        // while(!st.empty()){
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }
        // return "";
        while(k-- && !st.empty()){
            st.pop();
        }
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        int idx = 0;

        reverse(res.begin(), res.end());
        while(idx < res.size() && res[idx]=='0' ){
            idx++;
        }
        string ans = res.substr(idx);
        if(ans =="") return "0";
        return ans;
    }
};