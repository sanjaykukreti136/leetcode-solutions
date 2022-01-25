class Solution {
public:
    map<string,int>m;
    vector<int>res;
    int max_val , skills , peoples;
    vector<int>mask;
    
    void check(int idx , int sum , vector<int>&ans){
        if(sum>=max_val){
            if(res.size()==0 || res.size() > ans.size()) res = ans;
            return ;
        }
        if(idx == skills){
            if(res.size()==0 || res.size() > ans.size()) res = ans;
            return ;
        }
        if(res.size()>0 && ans.size() >= res.size()) return ;
        
        if(sum & (1<<idx) ){
            check(idx+1 , sum , ans);
        }else{
            for(int i=0;i<peoples;i++){
                if(mask[i] & (1<<idx)  ){
                    ans.push_back(i);
                    check(idx+1, mask[i] | sum , ans );
                    ans.pop_back();
                }
            }
        }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& v, vector<vector<string>>& p) {
        int i=0 ;
        skills = v.size() , peoples = p.size();
        for(auto  x : v){
           if(m.find(x)==m.end()) m[x] = i++; 
        }
        int z= m.size();
        max_val = (1<<z)-1;
        // mask.resize(peoples , 0);
        for(int i=0;i<p.size();i++){
            int temp = 0;
            for(int j=0;j<p[i].size();j++){
                int idx = m[p[i][j]];
                temp = temp |  (1<<idx);
            }
            mask.push_back(temp);
        }
        vector<int>ans;
        check( 0 , 0 , ans);
        return res;
        
    }
};