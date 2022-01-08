class Solution {
public:
    string capitalizeTitle(string s) {
        int idx = 0;
        for(int i=0;i<s.length();i++){
            s[i] = tolower(s[i]);
            if(isspace(s[i])){
                if(i-idx > 2){
                    s[idx] = toupper(s[idx]);
                }
                // idx = i+1;
            }
            if(i==0 || isspace(s[i-1])) idx = i;
            
        }
        
        if(s.length() - idx > 2){
            s[idx] = toupper(s[idx]);
        }
        
        return s;
        
    }
};