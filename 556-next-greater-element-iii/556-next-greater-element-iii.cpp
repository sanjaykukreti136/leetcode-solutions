class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int size=  s.length();
        int idx = -1;
        for(int i=size-2;i>=0;i--){
            if(s[i]<s[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1) return -1;
        int nidx = -1, val  = INT_MAX ;
        for(int i=idx+1;i<size;i++){
            if((s[i] > s[idx] )&& (s[i]-'0')<=val  ){
                nidx = i;
                val = s[i]-'0';
            }
        }
        if(nidx == -1) return -1;
        swap(s[idx] , s[nidx]);
        reverse(s.begin() + idx+1, s.end());
        long long x = stol(s);
        int res = pow(2 , 31)-1;
        if(x > res ) return -1;
        return stoi(s);
        
    }
};