class Solution {
public:
    vector<int> v;
    map<string,int> mp;
    int n; int m;
    int x;
    vector<int> pp;
    
    void fun(int id,int s,vector<int>& us){
        if(s >= x){
            // v.size() < 1 to take where when the vector v is empty then it's size is 0
            if(us.size() < v.size() || v.size() < 1){
                v = us;
            }
            return;
        }
        // to limit the no of recursive calls
        if(id == n ||(v.size()>0 && us.size() >= v.size()))
            return;
        
        int i;
        // if the ith skill is already included in the current s
        if(s & (1 << id))
            fun(id+1,s,us);
        else{
            // For every person which has that skill, we wouls try to recurr.
            for(i=0;i<m;i++){
                if(pp[i] & (1 << id)){
                    int p = s | pp[i];
                    us.push_back(i);
                    fun(id+1,p,us);
                    us.pop_back();
                }
            }
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& skills, vector<vector<string>>& pep) {
        n=skills.size();
        m=pep.size();
        
        int i,j;x=1;
        // storing every skill as key-value pair
        
        for(i=0;i<n;i++){
            mp[skills[i]]=i;
            x *= 2; 
        }
        x--; // The desired value when every skill would be included
       
        for(i=0;i<m;i++){
            int y=0;// stores the dcimal representation of every person skills
            
            for(j=0;j<pep[i].size();j++){
                y += (1 << mp[pep[i][j]]);
            }
            pp.push_back(y);
           // cout << y << "\n";
        }
        
        vector<int> bb;
        fun(0,0,bb);
        return v;
    }
};
// class Solution {
// public:
    
//     int ans = INT_MAX;
//     vector<int>fin;
//     void check(vector<int>&mask , int idx , int c , int mas , int max_val, vector<int>&temp){
        
//         if(idx == mask.size()){
//             if(mas == (1<<max_val)-1){
//                 // ans = min(ans , c);
//                 if(c < ans){
//                     ans = c;
//                     fin = temp;
//                 }
//             }
//             return ;
//         }
        
//         temp.push_back(idx);
//         check(mask , idx+1 , c+1 , (mas|mask[idx]) , max_val , temp);
//         temp.pop_back();
//         check(mask , idx+1 , c , mas , max_val, temp);
        
//     }
    
//     vector<int> smallestSufficientTeam(vector<string>& v, vector<vector<string>>& s) {
//         // for(a)
//         map<string,int>m;
//         int i=0;
//         for(auto x : v){
//             if(m.find(x)==m.end()) m[x] = i++;
//         }
//         int n = s.size();
//         vector<int>mask(n , 0);
//         for(int i=0;i<s.size();i++){
//             for(int j=0;j<s[i].size();j++){
//                 int idx = m[s[i][j]];
//                 mask[i] = (mask[i] | (1<<idx));
//             }
//         }
//         vector<int>temp;
//         int z = m.size();
//         check(mask , 0 , 0 , 0 , z , temp);
//         return fin;
        
//     }
// };