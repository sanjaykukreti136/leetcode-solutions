class Solution {
public:
    
    void check(int n, vector<vector<int>>&ans, vector<int>v , int k ,int box , int idx){
        if(box == k){
            ans.push_back(v);
            return ;
        }
        
        for(int i=idx;i<=n;i++){
            v.push_back(i);
            check(n, ans , v, k , box+1 , i+1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        // vector<int>
        check(n , ans , v , k , 0 , 1);
        return ans;
    }
};