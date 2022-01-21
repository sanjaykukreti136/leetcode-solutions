class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c = 0;
        int i=0;
        int j=0;
        int ans =0;
        while( j < nums.size()){
            /// acquire
            cout<<"x\n";
            while(j<nums.size()){
                
                if(nums[j]==0) c++;
                j++;
                if(c > k) break;
                ans = max(ans , j-i);
                cout<<ans<<"\n";
                // j++;
                
            }
            
            // release
            while(i<j && c>k){
                
                if(nums[i]==0){
                    c--;
                    i++;
                    break;
                }
                i++;
            }
        }
        return ans;
    }
};