class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        if(pattern[0]==pattern[1]){
            long long c =1;
            for(auto i : text){
                if(i==pattern[0]) c++;
            }
            return (c*(c-1))/2;
        }
        int n = text.size();
        vector<long long >v(n , 0);
        long long c = 0;
        for(int i=n-1;i>=0;i--){
            if(text[i]==pattern[1]){
                c++;
            }
            v[i] = c;
        }
        long long ans = 0;
        long long x = 0;
        for(int i=0;i<n;i++){
            if(text[i]==pattern[0]){
                x++;
                ans+=v[i];
            }
        }
        
        ans+= max(x ,v[0] );
        return ans;
        // return pattern[0]==pattern[1] ?  ans/2 : ans;
        
    }
};