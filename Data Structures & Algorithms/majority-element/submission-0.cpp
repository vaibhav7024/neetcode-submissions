class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0];
        int occ =1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==curr){
                occ++;
            }else {
                occ--;
            }

            if(occ==0){
                curr = nums[i];
                occ=1;
            }
        }
        return curr;
    }
};