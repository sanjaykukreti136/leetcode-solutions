class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>>pq;
        for(auto i : nums){
            pq.push(i);
        }
        
        while(k--){
            int x = pq.top();
            pq.pop();
            pq.push(x+1);
        }
        int mod = 1e9 + 7;
        long ans = 1 ;
        if(pq.size()==0) return 0;
        while(!pq.empty()){
            ans = (ans%mod * pq.top()%mod)%mod;
            pq.pop();
        }
        return ans;
    }
};