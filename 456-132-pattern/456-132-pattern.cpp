class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int prev = INT_MIN;
        stack<int>s;
        for(int i=nums.size()-1;i>=0;i--){
            while(!s.empty() && s.top() < nums[i]){
                if(prev > s.top()) return true;
                prev= s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return !s.empty() && prev > s.top();
    }
};