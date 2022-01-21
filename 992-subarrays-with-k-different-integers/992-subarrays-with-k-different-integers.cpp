class Solution {
public:
    int check(vector<int>&s, int k){
    int i=-1, j= -1;
    int ans=0;
    int n = s.size();
    map<int,int>m;
    while(j<n-1){
        while(j<n-1){
            j++;
            m[s[j]]++;
            if(m.size() > k) break;
            ans+= j-i;
        }
        while(i<j && m.size()>k){
            i++;
            m[s[i]]--;
            if(m[s[i]]==0){
                ans+= j-i;
                m.erase(s[i]);
                break;
            }
            
        }

    }
    return ans;
    // cout<<ans;
}
    
    int subarraysWithKDistinct(vector<int>& s, int k) {
     
        return check(s, k)-check(s,k-1);
    
    }
};

