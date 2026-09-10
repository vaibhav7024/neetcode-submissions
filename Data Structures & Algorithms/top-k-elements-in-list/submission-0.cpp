class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        vector<pair<int,int>> temp;
        for(auto a:m){
            temp.push_back({a.second,a.first});
        }
        sort(temp.rbegin(),temp.rend()); 
        vector<int > res(k);
        int i=0;
        for(auto a:temp){
            if(i==k){
                break;
            }
            res[i++]=a.second;
        }
        return res;
    }
};
