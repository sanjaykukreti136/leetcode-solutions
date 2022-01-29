class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int a=0,b=0, ans= 0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]>nums2[i]){
                a+=1;
            }else if(nums2[i]>nums1[i]){
                b+=1;
            }
            if(i==nums1.size()-1 || max(nums1[i], nums2[i])< min(nums1[i+1] , nums2[i+1]) ){
                ans+= min(a,b);
                a=b=0;
            }
        }
        return ans;
    }
};