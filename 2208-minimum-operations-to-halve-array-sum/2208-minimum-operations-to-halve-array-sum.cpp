class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double , vector<double>>pq;
        double sum =0 ;
        for(auto i  : nums){
            sum+=i;
            pq.push((double)i);
        }
        double s = sum;
        long long  c = 0 ;
        while(!pq.empty()){
            double t = pq.top();
            pq.pop();
            sum-=(t/2.0);
            t = (t/2.0);
            c++;
            // cout<<sum<<" "<<t<<"\n";
            if(sum<=(s/2.0)) return c;
            pq.push(t);
        }
        return c;
    }
};