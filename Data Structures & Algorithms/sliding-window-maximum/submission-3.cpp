class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0;
        while(i<k){
            while(!dq.empty() && dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i++]);
        }
        vector<int> ans;
        ans.push_back(dq.front());
        for(;i<nums.size();i++){
            if(nums[i-k]==dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};
