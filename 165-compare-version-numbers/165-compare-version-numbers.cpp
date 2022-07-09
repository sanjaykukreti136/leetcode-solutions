class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        string temp = "";
        for(auto i : version1){
            if(i=='.'){
                v1.push_back(stoi(temp));
                temp = "";
            }else{
                temp.push_back(i);
            }
        }
        if(temp.length()!=0){
            v1.push_back(stoi(temp));
        }
        temp = "";
        for(auto i : version2){
            if(i=='.'){
                v2.push_back(stoi(temp));
                temp = "";
            }else{
                temp.push_back(i);
            }
        }
        if(temp.length()!=0){
            v2.push_back(stoi(temp));
        }
        int i=0,j=0;
        for(auto i : v1) cout<<i<<" ";
        cout<<"\n";
        for(auto i : v2) cout<<i<<" ";
        while(i<v1.size() && j<v2.size()){
            if(v1[i] > v2[i]) return 1;
            else if(v1[i]<v2[i]) return -1;
            else{
                i++;
                j++;
            }
        }
        while(i<v1.size()){
            if(v1[i]>0) return 1;
            i++;
        }
        while(j<v2.size()){
            if(v2[j]>0) return -1;
            j++;
        }
        return 0;
    }
};