class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q2.push(x);
        }else 
            q1.push(x);
    }
    
    int pop() {
        int top;
        if(q1.empty()){
            int size = q2.size()-1;
            while(size--){
                q1.push(q2.front());
                q2.pop();
            }
            top=q2.front();
            q2.pop();
        }else{
            int size = q1.size()-1;
            while(size--){
                q2.push(q1.front());
                q1.pop();
            }
            top = q1.front();
            q1.pop();
        }
        return top;
    }
    
    int top() {
        int top ;
        if(q1.empty()){
            while(!q2.empty()){
                top = q2.front();
                q1.push(q2.front());
                q2.pop();
            }
        }else{
            while(!q1.empty()){
                top = q1.front();   
                q2.push(q1.front());
                q1.pop();
            }
        }
        return top;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */