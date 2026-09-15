class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            } 
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum = 1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }else if(sum<target){
                        k++;
                    }else
                        l--;
                }
            }
            i++;
        }
        return res;
    }
};