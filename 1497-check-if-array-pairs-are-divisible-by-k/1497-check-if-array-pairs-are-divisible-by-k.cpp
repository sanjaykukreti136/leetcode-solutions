class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>m;
        for(auto i : arr){
            // m[i%k]++;
            int rem = i%k;
            rem=(rem+k)%k;
            m[rem]++;
        }
        bool ans = true;
        for(auto i : m){
            int rem = i.first;
            int fre = i.second;
            
            if(( k%2==0 && rem==k/2 ) || (rem==0) ){
                if(fre%2!=0){
                    return false;
                }
            }else{
                int another = m.find(k-rem)==m.end() ? -1 : m[k-rem];
                if(another == -1 || another  != fre ){
                    return false;
                }
            }
        }
        return true;
    }
};