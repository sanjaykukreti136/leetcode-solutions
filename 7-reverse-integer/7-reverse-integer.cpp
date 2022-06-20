class Solution {
public:
    int reverse(int x) {
       long   int y= 0;
        bool flag=0;
        if(x<0)
        {
            flag= 1;
        }
        while(x)
        {
            y= y*10 + x%10;
            x=x/10;
        }
        if(flag==1)
        {
            y= 2*y- y;
        }
        
        if(y<INT_MIN || y>INT_MAX) return 0;
        return y;
    }
};