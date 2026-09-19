class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> temp;
        for(int i=0;i<speed.size();i++){
            temp.push_back({
                position[i],
                (double)(target-position[i])/speed[i]
            });
        }
        sort(temp.begin(),temp.end(),
            [](auto &a,auto &b){
                return a.first>b.first;
            }
        );
        int res=0;
        double maxtime = 0;
        for(auto &[car,time]:temp){
            if(maxtime<time){
                res++;
                maxtime=time;
            }
        }

        return res;
    }
};
