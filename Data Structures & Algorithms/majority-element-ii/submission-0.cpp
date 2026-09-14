class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        vector<int> res;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second>n) res.push_back(i.first);
        }
        return res;
    }
};