class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2==1) return {};
        long long a=2;
        vector<long long> v;
        while(finalSum>=a){
            finalSum-=a;
            v.push_back(a);
            a+=2;
        }
        v.back()+=finalSum;
        return v;
    }
};