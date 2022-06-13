class Solution {
public:
int minOperations(vector<int>& nums, int x) {
int n=nums.size();
int left=0,right=0;
int totalsum=0;
int currsum=0;
int ans=-1;
for(int i=0;i<n;i++){
totalsum+=nums[i];
}
if(totalsum<x){
return -1;
}
while(right<n){
currsum+=nums[right++];
while(currsum>totalsum-x && left<=right){
currsum-=nums[left++];
}
if(currsum == totalsum-x){
ans = max(ans,right-left);
}
}
return ans==-1?-1:n-ans;
}
};