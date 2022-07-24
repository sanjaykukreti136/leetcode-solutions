class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int>v(26,0);
        map<int,int>m;
        for(int i=0;i<5;i++){
            v[suits[i]-'a']++;
            if(v[suits[i]-'a']==5){
                return "Flush";
            }
        }
        for(int i=0;i<5;i++){
            m[ranks[i]]++;
        }
        string x="";
        for(auto it:m){
            if(it.second>2){
                x="Three of a Kind";
                return x;
            }
            else if(it.second==2){
                x="Pair";
            }
        }
        if(x=="Pair"){
            return "Pair";
        }
        return "High Card";
    }
};