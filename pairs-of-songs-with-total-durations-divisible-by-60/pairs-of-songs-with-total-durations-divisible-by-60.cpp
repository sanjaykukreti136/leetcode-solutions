class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
         int count[61] = {0};
        int ans = 0;
        
        for(int i = 0; i < time.size(); i++)
        {
            time[i] %= 60;
            
            if(count[60 - time[i]] > 0)
            {
                ans += count[60 - time[i]];
            }
            if(time[i] == 0)
                time[i] = 60;
            
            count[time[i]]++;
        }
        return ans;
    }
};