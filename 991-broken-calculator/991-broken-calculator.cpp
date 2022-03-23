class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int c = 0;
        while(target!=startValue){
            if(target > startValue){
                if(target%2==0) target/=2;
                else target+=1;
                c++;
            }else{
                target+=1;
                c++;
            }
        }
        return c;
    }
};