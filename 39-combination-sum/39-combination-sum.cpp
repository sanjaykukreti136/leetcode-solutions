class Solution {
public:
    
    void check(vector<int>v, vector<vector<int>>&ans, vector<int>t, int target , int idx){
        
        if(target ==0 ){
            ans.push_back(t);
            return ;
        }
        
        for(int i=idx;i<v.size();i++){
            if(target >= v[i]){
                t.push_back(v[i]);
                check(v, ans , t , target-v[i], i);
                t.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int tar) {
        vector<vector<int>>ans;
        vector<int>t;
        check(v , ans, t , tar , 0);
        return ans;
    }
};