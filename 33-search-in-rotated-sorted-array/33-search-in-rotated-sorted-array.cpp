class Solution {
public:
    
    
    int check(vector<int>nums){
        int i= 0, j = nums.size()-1;
        int ans = INT_MAX;
        int idx = -1;
        while(i<=j){
            int mid =  (i+j)/2;
            if(nums[mid] < ans || (nums[mid]==ans && mid<idx) ){
                ans = nums[mid];
                idx = mid;
            }
            if(nums[mid] > nums[j]){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        return idx;
    }
    
    int search(vector<int>& nums, int t) {
        int mid = check(nums);
        
        int s = 0 , e = nums.size()-1;
        int start = -1 , end = -1;
        
        if(t>=nums[mid] && t<=nums[e]){
            start = mid;
            end = e;
        }else{
            if(mid-1 < 0) return -1;
            start = 0;
            end = mid-1;
        }
        cout<<start<<" "<<end<<"\n";
        while(start<=end){
            int m = (start+end)/2;
            if(nums[m]==t) return m;
            else if(nums[m] < t){
                start = m+1;
            }else{
                end = m-1;
            }
        }
        return -1;
        
        
    }
};