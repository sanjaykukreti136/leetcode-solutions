class Solution {
public:
    int removePalindromeSub(string s) {
        int i=0, j = s.length()-1;
        int count = 0;
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else {
                return 2;
            }
        }
        return 1;
    }
};