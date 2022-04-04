class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int>m;
        
        for(int i=0;i<nums2.size();i++){
            int ans = -1;
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[j] > nums2[i]){
                    ans=  nums2[j];
                    break;
                }
            }
            m[nums2[i]] = ans;
        }
        vector<int>ans;
        for(auto i : nums1){
            if(m.find(i)!=m.end()){
                ans.push_back(m[i]);
            }
        }
        return ans;
//         1 3 4 2
//         3  4 -1 -1
        
//         1 = 3
//         3 = 4
//         4 = -1
//         2= -1;
        
//         4 1 2 
//         -1 3 -1
            
        // 1 3 4 2 
        
    }
};