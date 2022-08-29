class Solution {
public:
    int par[1001];
    
    int findpar(int a){
        if(a==par[a]) return a;
        return par[a] = findpar(par[a]);
    }
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if(accounts.size()==1){
            sort(accounts.begin()+1 , accounts.end());
            return accounts;
        }
        
        int n = accounts.size();
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        unordered_map<string,int>email_idx;
        vector<string>name(n);
        int i = 0 ;
        for(auto  j  : accounts){
            name[i] =  j[0];
            
            for(int k=1;k<j.size();k++){
                
                if(email_idx.find(j[k])!=email_idx.end()){
                    
                    par[findpar(i)] = findpar(email_idx[j[k]]);
                    
                }else{
                    email_idx[j[k]] = i;
                }
                
            }
            i++;
               
        }
        unordered_map<int,vector<string>>res_map;
        for(auto i : email_idx){
            int p = findpar(i.second);
            res_map[p].push_back(i.first);
        }
        
         vector<vector<string>> results;
        for(auto &r : res_map) {
            sort(r.second.begin(), r.second.end());
            r.second.insert(r.second.begin(), name[r.first]);
            results.push_back(r.second);
        }
        return results;
        
    }
};