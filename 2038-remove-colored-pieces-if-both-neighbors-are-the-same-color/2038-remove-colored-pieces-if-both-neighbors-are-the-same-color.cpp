class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0, b=0, ca =0, ba =0;
        for(auto ch : colors){
            if(ch=='A'){
                if(++ca > 2){
                    a++;
                }
                ba = 0;
            }else{
                if(++ba > 2){
                    b++;
                }
                ca =0;
            }
        }
        return a>b;
    }
};