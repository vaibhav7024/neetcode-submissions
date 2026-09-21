class Solution {
public:
    bool can(vector<int>& weights, int days,int cap){
        int curr = cap;
        int ship =1;
        for(int w : weights){
            if(curr-w<0){
                ship++;
                if(ship>days) return false;
                curr = cap;
            }
            curr-=w;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int res = r;
        while(l<=r){
            int cap = (l+r)/2;
            if(can(weights,days,cap)){
                res = min(res,cap);
                r = cap-1;
            }else{
                l = cap+1;
            }
        }
        return res;
    }
};