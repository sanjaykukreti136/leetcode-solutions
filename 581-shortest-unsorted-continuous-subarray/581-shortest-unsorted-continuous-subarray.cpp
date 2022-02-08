class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n);
        left[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            left[i] = min(left[i+1], nums[i]);
        }
        vector<int>right(n);
        right[0] = nums[0];
        for(int i=1;i<n;i++){
            right[i]  = max(right[i-1] , nums[i]);
        }
        for(auto i : left) cout<<i<<" ";
        cout<<"\n";
        for(auto i : right) cout<<i<<" ";
        int l=n, r=0;
        for(int i=0;i<left.size();i++){
            if(left[i]!=nums[i]){
                l = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(right[i]!=nums[i]){
                r = i;
                break;
            }
        }
        if(r < l) return 0;
        return (r-l+1);
        
        
        // return 5;
        
    }
};