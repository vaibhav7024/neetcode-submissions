class Solution {
public:
    int jump(vector<int>& nums) {
        int reach =0;
        int jump =0;
        int curr =0;
        if(nums.size()<=1) return jump;
        for(int i=0;i<nums.size()-1;i++){
            reach = max(reach,i+nums[i]);
            if(i==curr){
                jump++;
                curr = reach;
            }
        }
        return jump;
    }
};
