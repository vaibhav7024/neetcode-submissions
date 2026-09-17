class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for(int i=0;i<op.size();i++){
            if(op[i]=="C"){
                st.pop();
            }else if(op[i]=="D"){
                st.push(2*st.top());
            }else if(op[i]=="+"){
                int num=st.top();st.pop();
                int res = num+st.top();
                st.push(num);
                st.push(res);
            }else{
                st.push(stoi(op[i]));
            }
        }
        int res= 0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};