class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>res;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[i] >= st.top()){
                st.push(nums[i]);
            }
            else{
                while(!st.empty() && st.top()>nums[i] && (st.size() + 1  +( nums.size()-i-1 ))>k ){
                    st.pop();
                }
                st.push(nums[i]);
            }
        
        }
        while(st.size() > k){
            st.pop();
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin() , res.end());
        return res;
    }
    
};