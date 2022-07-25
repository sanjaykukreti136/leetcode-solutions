class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s =0;
        for(auto i: chalk){
            s+=i;
        }
        if(s > k ){
            for(int i=0;i<chalk.size();i++){
                if(chalk[i]>k) return i;
                k-=chalk[i];
            }
            return 0;
        }else{
            s = k%s;
            if(s==0) return 0;
            for(int i=0;i<chalk.size();i++){
                if(chalk[i]>s) return i;
                s-=chalk[i];
            }
        }
        return -1;
    }
};