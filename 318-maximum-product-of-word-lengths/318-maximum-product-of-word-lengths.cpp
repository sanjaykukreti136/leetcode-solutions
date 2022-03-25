class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>masks(n);
        int ans= 0;
        for(int i=0;i<n;i++){
            for(auto c : words[i]){
                masks[i] |= 1<<(c-'a');
            }
            
            for(int j=0;j<i;j++){
                if(!(masks[i]& masks[j])){
                    ans = max(ans , (int)(words[i].size()*words[j].size()) );
                }
            }
        }
        return ans;
    }
};