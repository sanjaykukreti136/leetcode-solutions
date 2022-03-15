class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        priority_queue<int,vector<int>>pq;
        for(auto i : nums){
            pq.push(i);
        }
        
        int prev = pq.top() ;
        pq.pop();
        int ans= 0;
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            ans = max(ans, abs(a-prev));
            prev  = a;
        }
        return ans;
        
        // sort(nums.begin(),nums.end());
        // int ans = 0;
        // for(int i=1;i<nums.size();i++){
        //     ans = max(ans , nums[i]-nums[i-1]);
        // }
        // return ans;
    }
};