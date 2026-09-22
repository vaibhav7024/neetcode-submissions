class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        int res = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(can(nums,k,mid)){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
    bool can(vector<int>& nums, int k, int largest){
        int subarray =1, currsum = 0;
        for(int num:nums){
            currsum+=num;
            if(currsum>largest){
                subarray++;
                if(subarray>k) return false;
                currsum = num;
            }
        }
        return true;
    }
};