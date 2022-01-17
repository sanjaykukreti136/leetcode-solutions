class Solution {
public :
    
    
    bool check(long long mid, long long k , vector<int>& nums1, vector<int>& nums2 ){
        
        long long c = 0;
        for(int i=0;i<nums1.size();i++){
            long long val = nums1[i];
            
            if(val ==0 && mid>=0){
                c+=nums2.size();
            }else if(val > 0){
                c+= findMax(val , mid , nums2);
            }else{
                c+= findMin(val , mid , nums2);
            }
        }
        return c>=k;
        
    }
    
    long long findMax(long long val , long long mid , vector<int>&nums){
        long long l =0, r= nums.size()-1;
        long long res = -1;
        while(l<=r){
            long long m = l + (r-l)/2;
            if(val*nums[m]<=mid){
                res = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return res+1;
    }
    
    
    long long findMin(long long val , long long mid , vector<int>&nums){
        long long l =0, r= nums.size()-1;
        long long res = r+1;
        while(l<=r){
            long long m = l + (r-l)/2;
            if(val*nums[m]<=mid){
                res = m;

                r = m-1;
            }else{
                l = m+1;

            }
        }
        return nums.size()-res;
    }
    
    
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
         long long l=-1e10,r=1e10,res=-1;
        
         while(l<=r){
             long long mid = l + (r-l)/2;
             if(check(mid, k, nums1 , nums2)){
                 res = mid ; 
                 r = mid-1;
             }else{
                 l = mid+1;
             }
         }
        return res;
    }
};