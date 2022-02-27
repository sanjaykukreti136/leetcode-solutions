class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
       int n = nums1.size();
       int m = nums2.size();
          int s = 0,  e= n;
          int t = n+m;
        if(n > m){
            return findMedianSortedArrays(nums2 , nums1);
        }
        
          while(s<=e){
              int aleft = s + (e-s)/2;
              int bleft = (t+1)/2- aleft;
              int alm1 = (aleft == 0) ? INT_MIN : nums1[aleft-1];
              int al = (aleft == n) ? INT_MAX : nums1[aleft];
              int blm1 = (bleft == 0)? INT_MIN : nums2[bleft-1];
              int bl = (bleft == m) ? INT_MAX : nums2[bleft];
              if(alm1 <= bl && blm1 <= al ){
                  double ans = 0.0;
                  int lmax = max( alm1 , blm1 );
                int rmin = min(al , bl);
                  if(t%2==0){

                      ans = (double)(lmax + rmin)/2.0;
                      return ans;
                  }else{
                      return (double)lmax;
                  }
              }else if(alm1> bl){
                  e = aleft-1;
              }else{
                  s = aleft+1;
              }
          }
      
     return 0.0;   
    }
};