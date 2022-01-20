class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        map<char,int>m;
        int s =0 , e= 0, ans = 0;
        while(e < str.size()){
            if(m.find(str[e])==m.end()){
                m[str[e]] = e;
                e++;
            }else{
                while(s<= m[str[e]]){
                    m.erase(str[s]);
                    s++;
                }
                m[str[e]] = e ; 
                e++;
            }
            int n= m.size();
            ans = max(ans , n);
            cout<<ans<<"\n";
        }
        return ans;
    }
};