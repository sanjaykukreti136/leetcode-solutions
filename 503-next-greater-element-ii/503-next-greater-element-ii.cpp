class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
    for(int i=nums.size()-1;i>=0;i--){
        st.push(nums[i]);
    }
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
            
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(st.top());
            }
            
            
            st.push(nums[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



// 2 3 1 9 5 7 8 9
    
   // 9 8 7 5 
   
// 8 = -1;
// 7 = 8
// 5 = 7
// 9 = -1   
// 1 = 9 
// 3 = 9 
// 2 = 3
//     [ 9 ,  3      ]