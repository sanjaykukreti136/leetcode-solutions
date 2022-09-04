class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int open = nums1.size()-1;
        if(i<0) nums1 = nums2; 
        while(j>=0 && i>=0){
            if(nums2[j] > nums1[i] ){
                nums1[open--] = nums2[j--];
            }
            else{
                nums1[open--] = nums1[i--];
            }
            
        }
        while(j>=0){
            nums1[open--] = nums2[j--];
        }
    }
};