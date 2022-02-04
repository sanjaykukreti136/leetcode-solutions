class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
        // int left[n] = {0};
        // int right[n] = {0};/
        vector<int>left(n,0);
        vector<int>right(n,0);
        int c= 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='L'){
                left[i] = 1;
                c= 1;
            }
            else if(s[i]=='R'){
                c=0;
                left[i] = 0;
            }
            else{
                if(c>0){
                    left[i]= c+1;
                    c++;
                }
            }
        }
        
        c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R'){
                right[i] = 1;
                c=1;
            }
            else if(s[i]=='L'){
                c=0;
            }
            else{
                if(c>0){
                    right[i] = c+1;
                    c++;
                }
            }
        }
        
    
        string ans = "";
        for(int i=0;i<n;i++){
            if(left[i]==right[i]){
                ans.push_back('.');
            }else{
                left[i] = (left[i]==0)?INT_MAX : left[i];
                right[i] = (right[i]==0)?INT_MAX : right[i];
                if(right[i]<left[i]){
                    ans.push_back('R');
                }else{
                    ans.push_back('L');
                }
            }
        }
        return ans;
        
        
    }
};