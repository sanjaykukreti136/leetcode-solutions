class Solution {
public:
    int twoEggDrop(int n) {
        int c=0, 
        r = 1;
        while(n>0){
            n-=r;
            r++;
            c++;
        }
        return c;
    }
};