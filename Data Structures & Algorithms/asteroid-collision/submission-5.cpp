class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i:asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && i<0 ){
                if(st.top()<-i)
                    st.pop();
                else if(st.top()==-i){
                    st.pop();
                    destroyed=true;
                    break;
                }else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                st.push(i);
            }
        }
        vector<int> res ;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};