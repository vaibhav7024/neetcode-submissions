class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=0;
        int k=0;
        for(int a:nums){
            if(a==0) i++;
            if(a==1) j++;
            if(a==2) k++;
        }
        int a=0;
        while(a<nums.size()){
            while(i--){
                nums[a++]=0;
            }
            while(j--){
                nums[a++]=1;
            }
            while(k--){
                nums[a++]=2;
            }
        }
    }
};