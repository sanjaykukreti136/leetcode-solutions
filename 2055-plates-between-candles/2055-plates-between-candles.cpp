class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
       int n = s.length();
       vector<int>aage(n);
        vector<int>piche(n);
        int val = -1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='|'){
                val = i;
            }
            aage[i] = val;
        }
        val = -1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='|'){
                val = i;
            }
            piche[i] = val;
        }

        int c=0;
        // map<int,int>m;
        vector<int>m(n+1 , 0 );
        // m[-1] = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                c+=1;
            }else{
                 m[i]= c;
            }
        }
        vector<int>ans;
        for(auto i : queries){
            int f = i[0];
            int se = i[1];
            int c1 , c2;
            if(piche[f]==-1){
                ans.push_back(0);
                continue;
            }else{
                c1 = m[piche[f]];
            }
            
            if(aage[se] == -1){
                ans.push_back(0);
                continue;
            }else{
                c2 = m[aage[se]];
            }
            
            if(aage[se] < piche[f]){
                ans.push_back(0);
            }else{
            ans.push_back(c2-c1);
            }
        }
        return ans;
    }
};