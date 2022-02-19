class Solution {
public:
    
    int minimumDeviation(vector<int>& nums) {
        set<int> ss;
        for(auto it:nums){
            if(it & 1) ss.insert(it*2);
            else ss.insert(it);
        }
        int maxi = *ss.rbegin();   // will give iterator of the largest element
        int mini = *ss.begin();   // will give iterator of the smallest element
        int ans = INT_MAX;
        while(*ss.rbegin()%2==0){
            int currMax = *ss.rbegin();
            ss.erase(currMax);
            ss.insert(currMax/2);
            ans = min(ans,*ss.rbegin()-*ss.begin());
        }
        return ans;
    }
};