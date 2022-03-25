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