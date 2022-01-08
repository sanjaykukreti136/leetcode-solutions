class Solution {
public:
    int longestPalindrome(vector<string>& s) {
        map<string , int>m;
        int c=0;
        for(int i=0;i<s.size();i++){
            string  t = s[i];
            reverse(t.begin(), t.end());
            if(m.find(t)!=m.end() && m[t]>0){
                m[t]-=1;
                c+=4;
            }else{

                if(m.find(s[i])==m.end()){
                    m[s[i]]=1;
                }else{
                    
                    m[s[i]]+=1;
                }
            }
        }
        
        for(auto i : s){
            if(i[0]==i[1] && m[i]>0 ){
                c+=2;
                break;
            }
        }
        return c;
        
    }
};