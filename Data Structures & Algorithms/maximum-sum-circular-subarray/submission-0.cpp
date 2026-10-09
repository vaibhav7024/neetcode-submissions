class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int currmax=0,currmin = 0;
        int maxsum =INT_MIN, minsum = INT_MAX;
        int total=0;
        for(int i=0;i<n;i++){
            currmax = max(nums[i] , currmax+nums[i]);
            maxsum = max(currmax,maxsum);

            currmin = min(nums[i],currmin+nums[i]);
            minsum = min(currmin,minsum);
            total+=nums[i];
        }
        if(maxsum<0) return maxsum;
        return max(maxsum,total-minsum);
    }
};