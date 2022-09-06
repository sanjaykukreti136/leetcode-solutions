class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        int i , j , sum;
        vector<int> v;
        for(i=0 ; ;i++)
        {
            for(j=0 ; ;j++)
            {
                sum = 0;
                sum = pow(x,i) + pow(y,j);
                if(sum<=bound)
                   s.insert(sum);
                if(y==1 || pow(y,j) > bound)
                    break;
            }
            if(x==1 || pow(x,i) > bound)
                    break;
        }
        for(auto x: s)
        {
            v.push_back(x);
        }
        return v;    
    }
};