// class Solution {
// public:
    
    
//     map<vector<int> , int>m;
//     int check(vector<vector<int>>&v, vector<int>&need , int idx , int sum){
        
//         if(m[need]>0) return m[need];
        
        
        
//     }
class Solution {
public:
    bool check(vector<int> need){
        for(int i = 0; i < need.size(); i++){
            if(need[i] < 0){
                return false;
            }
        }
        return true;
    }
    map<vector<int>, int> umap;
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(umap[needs] > 0){
            return umap[needs];
        }
        int minimum = 0;
        for(int i = 0; i < needs.size(); i++){
            minimum += needs[i] * price[i];
        }        
        for(auto spec : special){
            vector<int> need = needs;
            for(int i = 0; i < need.size(); i++){
                need[i] -= spec[i];
            }
            if(check(need)){
                minimum = min(minimum, spec[spec.size() - 1] + shoppingOffers(price, special, need));    
            }            
        }
        return umap[needs] = minimum;
    }

//     int ans = INT_MAX;
    
//     int check(vector<vector<int>>&v, vector<int>&need , int idx , int sum){
//         if(idx >= v.size()){
//             for(auto i : need){
//                 if(i!=0) return INT_MAX;
//             }
//             ans = min(ans , sum);
//             return 0;
//         }
//         vector<int>temp= need;
//         int n = v[idx].size();
//         bool flag = true;
//         for(int i=0;i<v[idx].size()-1;i++){
//             if(need[i]>=v[idx][i]){
//                 need[i]-=v[idx][i];
//             }else{
//                 flag = false;
//                 break;
//             }
//         }
//         int a = INT_MAX;
//         if(flag){
//             a = check(v , need , idx, sum+v[idx][n-1]);
//         }
//         int b = check(v, temp , idx+1 , sum);
        
//         if(a == INT_MAX && b==INT_MAX) return a;
//         // return min(a , b) + v[idx][n-1];      
//         if(a!=INT_MAX) return min()
//     }
    
//     int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
//         int n = price.size();
//         for(int i=0;i<price.size();i++){
//             vector<int>temp(n+1 , 0);
//             temp[n] = price[i];
//             temp[i] = 1;
//             special.push_back(temp);
//         }
        
        
//          check(special , needs  , 0 , 0 );
//          return ans;
        
//     }
    
    
    
    
};