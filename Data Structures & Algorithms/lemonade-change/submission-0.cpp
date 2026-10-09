class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> m;

        for(int i=0;i<bills.size();i++){
            if(i==0 && bills[i]!=5)
                return false;
            else if(bills[i]==5){
                m[5]++;
            }else{
                int num = bills[i];
                while(num>5){
                    if(m[10]>0 && num>10){
                        num-=10;
                        m[10]--;
                    }else if(m[5]>0 && num>5){
                        num-=5;
                        m[5]--;
                    }else{
                        return false;
                    }
                }
                m[bills[i]]++;
            }
        }
        return true;
    }
};