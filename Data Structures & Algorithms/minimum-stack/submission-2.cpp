class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            min = val;
            st.push(0);
        }else{
            st.push((long long)val-min);
            if(min>val)
                min = val;
        }
    }
    
    void pop() {
        if(st.top()>=0){
            st.pop();
        }else{
            min = 1LL*min-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<=0){
            return min;
        }else 
            return min+st.top();
    }
    
    int getMin() {
        return min;
    }
};
