class Solution {
public:
    void check(int l , int h, int v , vector<int>&ans){
        if(v>h) return ;
        if(v>=l && v<=h) ans.push_back(v);
        int x = v%10;
      if(x<9)  check(l , h , v*10+x+1  , ans);
        
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
        check(low , high , i , ans);
            // cout<<ans.size()<<"\n";
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};