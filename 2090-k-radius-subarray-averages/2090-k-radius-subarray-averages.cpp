class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>v(nums.size(), -1);
        int i=0, j = k*2;
        long long  ans=0;
        if(j<nums.size()){
            for(int x=0;x<=j;x++){
                ans+=nums[x];
            }
        }
        int size = k*2+1;
        while(j<nums.size()){
            int mid = (i+j)/2;
           
            v[mid] = ans/size;
            
            j++;
            i++;
            if(j<nums.size()){
                ans+=nums[j];
                ans-=nums[i-1];
            }
            
        }
        return v;
    }
};