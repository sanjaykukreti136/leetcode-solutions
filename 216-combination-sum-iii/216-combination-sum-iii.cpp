class Solution {
public:
    
    void check(vector<vector<int>>&ans, vector<int>v, int idx , int k , int n, int t){
        
        if(v.size()==k && t==0 ){
            ans.push_back(v);
            return ;
        }
        
        for(int i=idx;i<=9;i++){
            if(t>=i){
                v.push_back(i);
                check(ans, v, i+1 , k , n , t-i);
                v.pop_back();
            }   
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        check(ans , v , 1 , k , n, n);
        return ans;
    }
};