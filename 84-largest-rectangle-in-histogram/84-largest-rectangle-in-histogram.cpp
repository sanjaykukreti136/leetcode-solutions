class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int ans = 0;
        int i = 0;
        int n = v.size();
        stack<int>st;
        while(i<n){
            if(st.empty() || v[i]>=v[st.top()]){
                st.push(i++);
            }else{
                int idx = st.top();
                st.pop();
                int curr = v[idx]*(st.empty()?i:i-1-st.top());
                if(curr > ans){
                    ans = curr;
                }
            }
        }
        while(!st.empty()){
            int idx = st.top();
                st.pop();
                int curr = v[idx]*(st.empty()?i:i-1-st.top());
                if(curr > ans){
                    ans = curr;
            }
        }
        return ans;
    }
};