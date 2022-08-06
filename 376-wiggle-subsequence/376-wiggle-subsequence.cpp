class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int>v(n);
        if(n==0) return 1;
        for(int i=1;i<nums.size();i++){
            v[i-1] = nums[i]-nums[i-1];
        }
        int c = 1;
        // bool pos = v[0]>0 ? true : false;
        int idx = 0;
        while( idx<n && v[idx]==0) idx++;
        if(idx==n) return 1;
        bool pos = v[idx]>0 ? true : false;
        for(int i=idx+1;i<n;i++){
            if(v[i]==0) continue;
            if(pos){
                if(v[i] < 0 ) c++;
            }else{
                if(v[i] > 0) c++;
            }
            pos = v[i] >0?true : false;
            
        }
        return c+1;
    }
};