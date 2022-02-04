class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int j = -1;
        for(int i=s.length()-1;i>0;i--){
            if(s[i]>s[i-1]){
                j = i-1;
                break;
            }
        }
        if(j==-1) return -1;
        char ch = 'A';
        int idx = -1;
        cout<<j<<"\n";
        for(int i=s.length()-1;i>j;i--){
            if(s[i]>s[j] && s[i]<ch){
                ch = s[i];
                idx = i;
            }
        }
        if(idx == -1) return -1;
        cout<<idx;
        swap(s[j]  , s[idx]);
        j= j+1;
        idx = s.length()-1;
        while(j<=idx){
            swap(s[j], s[idx]);
            j++;
            idx--;
        }
        // return (int)stol(s);
        long a = stol(s);
        if(a>INT_MAX || a<n) return -1;
        return (int)a;
    }
};