class Solution {
public:
        vector<int>maxNumberr(vector<int>v , int k ){
        int d= v.size() - k;
        
        vector<int>res;
        for(int a : v){
            while(d && res.size() && res.back() < a  ){
                res.pop_back();
                d--;
            }
            res.push_back(a);
        }
        res.resize(k);
        return res;
    }
    
    vector<int> maxNumbers(vector<int> nums1, vector<int> nums2) {
//         vector<int>res;
//         int i=0, j=0;
//         for(auto i : nums1) cout<<i<<" ";
//         cout<<"\n";
//         for(auto i : nums2) cout<<i<<" ";
//         while(i < nums1.size() && j<nums2.size()){
//             if(nums1[i] > nums2[j]){
//                 res.push_back(nums1[i++]);
//             }else if(nums1[i] < nums2[j]){
//                 res.push_back(nums2[j++]);
//             }else{
//                 res.push_back(nums1[i++]);
//                 res.push_back(nums2[++]);
                
//             }
//         }
//         while(i < nums1.size()){
//             res.push_back(nums1[i++]);
//         }
//         while(j < nums2.size()){
//             res.push_back(nums2[j++]);
//         }
//         return res;
    vector<int> out;
    auto i1 = nums1.begin(), end1 = nums1.end();
    auto i2 = nums2.begin(), end2 = nums2.end();
    while (i1 != end1 || i2 != end2)
        out.push_back(lexicographical_compare(i1, end1, i2, end2) ? *i2++ : *i1++);
    return out;
}
 
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size() , n2= nums2.size();
        vector<int>res;
        
        for(int i=max(k-n2 , 0);i<=min(k,n1);i++){
            res = max(res , maxNumbers( maxNumberr(nums1 , i) , maxNumberr(nums2 , k-i) )  );
        }
        return res;
    }
    

    
};