
class Solution {
public:
    int distinctEchoSubstrings(string sx) {
        set<string_view >se;
        for(int i=1;i<=sx.length()/2;i++){
            int start = 0 , next = i;
            int c = 0;
          string_view s = sx;
            while(next < s.length()){
                if(s[start]==s[next]){
                    c++;
                }else{
                    c = 0;
                }
                if(c == i){

                    string_view  temp = s.substr(start-c+1 ,2*c);
                    se.insert(temp);
                    c--;
                }
                start++;
                next++;
            }
        }
        return se.size();
    }
};