class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i = 0, j = 0;
        while(s1[i] != '\0' || s2[j] != '\0'){
            int a = 0, b = 0;
            while(isdigit(s1[i])){
                a = a*10 + (s1[i]-'0');
                i += 1;
            }
            while(isdigit(s2[j])){
                b = b*10 + (s2[j]-'0');
                j += 1;
            }
            if(a < b)
                return -1;
            if(a > b)
                return 1;
            if(s1[i] == '.')
                i += 1;
            if(s2[j] == '.')
                j += 1;
        }
        return 0;
    }
};