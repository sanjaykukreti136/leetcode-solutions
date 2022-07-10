class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0]=='-'){
            string t = "-";
            for(int i=1;i<n.size();i++){
                if((n[i]-'0')>x){
                    return t+to_string(x)+n.substr(i);
                }
                t+=n[i];
            }
            return n+to_string(x);
        }else{
            string t = "";
            for(int i=0;i<n.size();i++){
                if((n[i]-'0')<x){
                    return t+to_string(x)+n.substr(i);
                }
                t+=n[i];
            }
            return n+to_string(x);
            
        }
        return "";
    }
};