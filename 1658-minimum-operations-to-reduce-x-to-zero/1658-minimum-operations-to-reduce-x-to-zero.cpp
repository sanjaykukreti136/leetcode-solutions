class Solution {
public:
    
    int min(int a, int b){
        return (a<b) ? a : b;
    }
    
    
    int first(vector<int>nums, int x){
        int s =0;
        unordered_map<int,int>m;
        for(int i=nums.size()-1;i>=0;i--){
            s+=nums[i];
            m[s] = i;
        }
        
        int res = INT_MAX;
        if(m.find(x)!=m.end()){
            res = nums.size()-m[x];
        }
        
        s = 0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(m.find(x-s)!=m.end() && m[x-s]>i){
                res = min(res , (i+1)+(nums.size() - m[x-s]) );
            }
        }
        
        if(res == INT_MAX) return -1;
        return res;
        
    }
    int second(vector<int>nums,int x){
        int s =0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            m[s] = i;
        }
        
        int res = INT_MAX;
        if(m.find(x)!=m.end()){
            res = m[x]+1;
        }
        
        s = 0;
        for(int i=nums.size()-1;i>=0;i--){
            s+=nums[i];
            if(m.find(x-s)!=m.end() && m[x-s]<i ){
                res = min(res , (nums.size() - i )+(m[x-s]+1) );
            }
        }
        
        if(res == INT_MAX) return -1;
        return res;
        
    }
    int minOperations(vector<int>& nums, int x) {
         // return min( first(nums,x) , second(nums,x) );
        int a = first(nums,x);
        int b = second(nums,x);
        a = (a==-1) ? INT_MAX : a;
        b= (b==-1) ? INT_MAX : b;
        int res = min(a,b)==INT_MAX ? -1 : min(a,b);
        return res;
    }
};