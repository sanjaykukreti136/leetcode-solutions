class Solution {
public:
    int titleToNumber(string s) {
        long long  sum =0;
        int x = 0;
        for(int i=s.length()-1;i>=0;i--){
            sum+= pow(26, x)*(s[i]-'A' + 1);
           
            x++;
        }
        return sum;
        
    }
};