class Solution {
public:
    int eval(int a, int b, string ch){
        if(ch=="+"){
            return b+a;
        }else if(ch=="-"){
            return b-a;
        }else if(ch=="*"){
            return b*a;
        }
            return b/a;
        
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int v2 = st.top();st.pop();
                int v1 = st.top();st.pop();
                st.push(eval(v2,v1,s));
            }else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
