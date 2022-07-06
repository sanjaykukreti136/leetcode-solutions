class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0) return nums[0];
        if(k==1 && nums.size()<2) return -1;
        if(k==1) return nums[1];
        if(k > nums.size()){
            if(nums.size()==1){
        int res  =   k%2==0 ?  *max_element(nums.begin(),nums.end()) :   -1;
                return res;
            }else{
                return *max_element(nums.begin(),nums.end());
            }

        }
        if(k==nums.size()){
            int maxv = INT_MIN;
            k-=1;
            int i=0;
            while(k--){
            maxv = max(maxv , nums[i++]);
            }
            return maxv;
        }else{
            int x = k;
            x-=1;
            int maxv = INT_MIN;
            int i=0;
            while(x--){
            maxv = max(maxv , nums[i++]);
            }
            return max(maxv , nums[k]);
        }
        
        return 0;
        // return max(maxv , nums[i]);
    }
};