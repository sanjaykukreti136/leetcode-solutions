class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>small(n , 0);
        small[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            small[i] = min(nums[i], small[i+1]);
        }
        
        vector<int>large(n , 0);
        large[0] = nums[0];
        for(int i=1;i<n;i++){
            large[i] = max(nums[i], large[i-1]);
        }
        
        int first = -1;
        for(int i=0;i<n;i++){
            if(small[i]!=nums[i]){
                first = i;
                break;
            }
        }
        
        int sec = -1;
        for(int i=n-1;i>=0;i--){
            if(large[i]!=nums[i]){
                sec  =i;
                break;
            }
        }
        if(first==-1 && sec==-1) return 0;
        return sec-first+1;
    }
};