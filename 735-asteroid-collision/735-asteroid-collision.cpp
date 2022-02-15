class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        vector<int>ans;
        // return v;
        stack<int>st;
        for(auto i : v){
            if(i>0 || st.empty() || (st.top()<0 && i<0)){
                st.push(i);
            }else{
                if(abs(i)==st.top()){
                    st.pop();
                    continue;
                }
                while(!st.empty() && st.top()<abs(i) && st.top()>0){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(i)){
                    st.pop();
                }
                else if(st.empty() || st.top()<0) st.push(i);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};