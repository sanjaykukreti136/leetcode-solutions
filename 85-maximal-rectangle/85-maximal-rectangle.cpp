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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>v(m, 0 );
        int ans = 0;
        for(auto i : matrix){
            for(int j=0;j<m;j++){
                if(i[j]=='0'){
                    v[j] = 0;
                }else{
                v[j]+=(i[j]-'0');
                }
            }
            for(auto x : v){
                cout<<x<<" ";
            }
            cout<<"\n";
            ans = max(ans,largestRectangleArea(v) );
        }
        return ans;
    }
};