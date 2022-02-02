class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int a[n+1]; 
        a[n] = INT_MAX;
        for(int i=n-1;i>=0;i--){
            // if()
            a[i] = min(a[i+1] , nums[i]);
        }
        int max_val = 0;
        for(int i=0;i<n;i++){
            max_val = max(max_val , nums[i]);
            if(max_val <= a[i+1] ){
                return i+1;
            }
        }
        return -1;
    }
};