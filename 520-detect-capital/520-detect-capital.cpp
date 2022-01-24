class Solution {
public:
    bool detectCapitalUse(string word) {
        bool a=true ,b=true , c=false;
        int co = 0;
        for(int i=0;i<word.length();i++){
            if(i==0 && ( word[i]>='A' && word[i]<='Z'  )){
                c = true;
            }
            else if(i!=0 && ( word[i]>='A' && word[i]<='Z'  ) ){
                b = false;
            }
            if(( word[i]>='A' && word[i]<='Z'  )){
                co++;
            }
        }
        if(co == word.length()) return true;
        else if(co==1 && c==true  ) return true;
        else if(co==0) return true;
        return false;
    }
};