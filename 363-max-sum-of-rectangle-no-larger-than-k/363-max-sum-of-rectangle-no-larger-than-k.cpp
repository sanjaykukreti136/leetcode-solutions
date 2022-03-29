class Solution {
public:
    
    
    vector<int>add(vector<int>curr , vector<int>prev){
        vector<int>ans;
        for(int i=0;i<curr.size();i++){
            ans.push_back(curr[i] + prev[i]);
        }
        return ans;
    }
    
 int kadane(vector<int> a,int k){
        int ans=INT_MIN,cs=0,p=0;
        set<int> st;
        st.insert(0);
        for(int i=0;i<a.size();i++){
            cs+=a[i];
            if((cs-p)<=k)
                ans=max(ans,cs-p);
            else{
                auto it=st.lower_bound(cs-k);
                if(it!=st.end())
                    ans=max(ans,cs-*it);
            }
            st.insert(cs);
            p=min(p,cs);
        }
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int res = INT_MIN;
        int r = matrix.size(), c= matrix[0].size();
        for(int i=0;i<r;i++){
            vector<int>prev(c , 0);
            for(int j=  i;j<r;j++){
                
                vector<int>curr = matrix[j];
                prev =   add(curr , prev);
                
                int val = kadane(prev , k );
                if(val>= res){
                    res =  val;
                }
                
            }
        }
        return res ; 
        
    }
};