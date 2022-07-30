class Solution {
public:
    
    class pair1{
        public : 
           int ls, lg, rs, rg;
            
           pair1(int a, int b, int c, int d ){
               ls = a;
               lg = b;
               rs = c;
               rg = d;
           }
    };
    
    
    void left(vector<int>&nums , vector<pair1*>&v){
        int n = nums.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            
            while(!s.empty() && nums[s.top()]<=nums[i] ){
                s.pop();
            }
            
            if(!s.empty()){
                v[i]->lg = i-s.top();
            }else{
                v[i]->lg = i+1;
            }
            
            s.push(i);
            
        }
        while(!s.empty()) s.pop();
        
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>=nums[i] ){
                s.pop();
            }
            if(!s.empty()){
                v[i]->ls = i-s.top();
            }else{
                v[i]->ls= i+1;
            }
            s.push(i);
        }
        
    }
    
    void right(vector<int>&nums , vector<pair1*>&v){
        int n = nums.size();
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            
            while(!s.empty() && nums[s.top()]<nums[i] ){
                s.pop();
            }
            
            if(!s.empty()){
                v[i]->rg = s.top()-i;
            }else{
                v[i]->rg = n-i;
            }
            
            s.push(i);
            
        }
        while(!s.empty()) s.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>nums[i] ){
                s.pop();
            }
            if(!s.empty()){
                v[i]->rs = s.top()-i;
            }else{
                v[i]->rs= n-i;
            }
            s.push(i);
        }
        
    }
    

    
    
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<pair1 *>v(n);
        for(int i=0;i<n;i++){
            pair1 *p = new pair1(0,0,0,0);
            v[i] = p;
        }
        left(nums, v);
        right(nums,v);
        long long ans = 0;
        int k =0;
        for(auto i  : v){
            
            // cout<<i->lg<<"  "<<i->ls<<"   "<<i->rg<<"   "<<i->rs<<"\n";
            ans+= (nums[k++])*((long long)(i->lg*i->rg) - (long long)(i->ls*i->rs) );
            // cout<<ans<<"\n";
            // ans+=nums[k]*(i->lg + i->rg);
            // ans-= nums[k++]*(i->ls+i->rs);
        }
        return ans;
    }
};