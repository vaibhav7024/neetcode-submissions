class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre = nums;
        vector<int> post = nums;
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]*pre[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
            post[i]=post[i]*post[i+1];
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(i==0){
                nums[i]=post[i+1];
            }else if(i==nums.size()-1){
                nums[i]=pre[i-1];
            }else{
                nums[i]=pre[i-1]*post[i+1];
            }
        }
        return nums;
    }
};
