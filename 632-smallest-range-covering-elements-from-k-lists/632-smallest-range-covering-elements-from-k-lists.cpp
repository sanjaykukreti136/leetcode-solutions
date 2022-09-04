class Solution {
    
    
    
public:
    
    class element{
        public:
        int value;
        int idx;
        int row;
        int size;
        
        element(int v, int i , int r, int s){
            value = v;
            idx= i;
            row = r;
            size = s;
        }
    };
    
    struct compare{
        bool operator()(element a, element b){
            return a.value > b.value;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mn = INT_MAX, mx = INT_MIN , range  = INT_MAX;
        priority_queue<element , vector<element>, compare>p;
        int k = nums.size();
        
        for(int i=0;i<k;i++){
            p.push(element(nums[i][0], 0 , i , nums[i].size() ));
            mn = min(mn , nums[i][0]);
            mx = max(mx , nums[i][0]);
        }
        int low , high;
        while(!p.empty()){
            element t = p.top();
            p.pop();
            int mayval = t.value;
            if(range > mx-mayval){
                range = mx-mayval;
                mn = mayval;
                low = mn;
                high = mx;
            }
            
            if(t.idx== t.size-1) break;
            
            t.idx+=1;
            
            p.push(element(nums[t.row][t.idx], t.idx, t.row , t.size ));
            
            mx= max(mx , nums[t.row][t.idx] );
            
            
        }
        vector<int>v{low, high};
        return v;
    }
};