class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>left;
        vector<int>right;
        
        int p = INT_MAX;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                left.push_back(0);
                p = i;
            }else{
                // left.p
                if(p==INT_MAX) left.push_back(p);
                else left.push_back(i-p);
            }
        }
        
        // 1 2 3 1 
        // 3  2  1  1
        
        p = INT_MAX;
        for(int i=seats.size()-1;i>=0;i--){
            if(seats[i]==1){
                right.push_back(0);
                p = i;
            }else{
                // left.p
                if(p==INT_MAX) right.push_back(p);
                else right.push_back(p-i);
            }
        }
        reverse(right.begin(),right.end());
        int ans = 0;
        for(int i=0;i<seats.size();i++){
        if(seats[i]==0){
            cout<<left[i]<<" - "<<right[i]<<"\n";
            ans = max(ans , min(left[i], right[i]) );
        }
        }
        return ans;
        
        
    }
};