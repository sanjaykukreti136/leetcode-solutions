class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0 , j=0;
        if(name.size() > typed.size()) return false;
        while(j<typed.length() && i<name.length()){
            if(typed[j]==name[i]){
                i++;
                j++;
            }else if(j>0 && typed[j]==typed[j-1]){
                j++;
            }else{
                return false;
            }
        }
        if(i!=name.length()) return false;
        while(j<typed.length()){
            if(j<=0 || typed[j]!=typed[j-1] ) return false;
            j++;
        }
        return true;
    }
};