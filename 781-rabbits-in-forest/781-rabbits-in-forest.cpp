class Solution {
public:
    int numRabbits(vector<int>& a) {
    map<int,int>m;
    // int a[n];
    for(int i=0;i<a.size();i++){
        // cin>>a[i];
        m[a[i]]++;
    }
    
    int ans = 0;
    for(auto i : m){
        int seats = i.first + 1;
        int val  =i.second;
        int y = (ceil)((double)val/seats);
        ans += y*seats;
        
        
    }
    return ans;
    }
};