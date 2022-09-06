class Solution {
public:
    static bool comp(int &a , int &b){
        if(a<0 && b<0) return b<a;
        return a<b;
    }
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto i : arr) m[i]++;
        sort(arr.begin(),arr.end() , comp);
        for(auto i : arr ) cout<<i<<" ";
        for(auto i : arr){
            if(m.find(i)==m.end()) continue;
            if(m.find(2*i)==m.end()) return false;
            m[i]-=1;
            m[2*i]-=1;
            if(m[i]==0) m.erase(i);
            if(m[2*i]==0) m.erase(2*i);
        }
        return true;
    }
};