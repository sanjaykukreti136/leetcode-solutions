class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int minv = INT_MAX;
        int maxv = INT_MIN;
        for(auto i : nums){
            minv = min(i, minv);
            maxv = max(i, maxv);
        }
        int n = nums.size();
        if(n<2) return 0;
    
        int interval = ceil((maxv-minv+0.0)/(n-1));
        int buk = n-1;
        vector<int>maxi(buk, -1);
        vector<int>mini(buk , INT_MAX);
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]== minv || nums[i]==maxv) continue;
            int idx = ((nums[i]-minv)/(interval));
            
            maxi[idx] = max(maxi[idx], nums[i]);
            mini[idx]  = min(mini[idx], nums[i]);
            
        }
        
        int prev = minv;
        int res = 0;
        for(int i=0;i<n-1;i++){
            if(maxi[i]==-1) continue;
            
            res = max(res , mini[i]-prev);
            prev = maxi[i];
        }
        res = max(maxv - prev , res);
        return res;
    }
};