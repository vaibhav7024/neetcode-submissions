class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0, mid=0, t=nums.size()-1;
        while(mid<=t){
            if(nums[mid]==0){
                swap(nums[z],nums[mid]);
                z++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[t]);
                t--;
            }
        }
    }
};