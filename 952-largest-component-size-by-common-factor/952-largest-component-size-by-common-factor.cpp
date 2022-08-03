class Solution {
public:
    
    
    int find_par(int a , vector<int>&par){
        if(a==par[a]) return a;
        return par[a] = find_par(par[a], par);
    }
    
    void do_union(int a , int b , vector<int>&par){
        par[find_par(a,par)] = par[find_par(b,par)];
    }
    
    int largestComponentSize(vector<int>& nums) {
        
        int n = *max_element(nums.begin(), nums.end());
        vector<int>par(n+1);
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
        
        for(auto i : nums){
            for(int  k=2;k<=sqrt(i);k++){
                if(i%k==0){
                    do_union(i , k,par);
                    do_union(i , i/k,par);
                }
            }
        }
        
        unordered_map<int,int>m;
        int ans = 0;
        for(auto i : nums){
            ans = max(ans , ++m[find_par(i , par)] );
        }
        return ans;
        
        
    }
};