class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        int mask =1;
        for(int i=0;i<32;i++){
            cout<<n<<"\n";
            if((n & 1)!=0) c++;
            n = n >>1;
        }
        return c;
    }
};