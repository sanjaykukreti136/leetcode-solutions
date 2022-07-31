class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for(char a='a';a<='z';a++){
            for(char b='a';b<='z';b++){
                
                if(a==b) continue;
                
                int af = 0, bf = 0;
                bool over = false;
                for(auto i : s){
                    if(i==a) af++;
                    else if(i==b) bf++;
                    
                    if(bf > 0){
                        ans = max(ans , af-bf);
                    }else{
                        if(over){
                            ans = max(ans , af-1);
                        }
                    }
                    if(bf > af){
                        af = 0;
                        bf = 0;
                        over = true;
                    }
                    
                }
                
                
            }
        }
        return ans;
    }
};