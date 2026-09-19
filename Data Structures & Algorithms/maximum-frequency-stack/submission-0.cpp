class FreqStack {
public:
    unordered_map<int,int> m;
    unordered_map<int,stack<int>> freq;
    int maxfreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        freq[m[val]].push(val);
        if(maxfreq<m[val])
            maxfreq = m[val];
    }
    
    int pop() {
        int f = freq[maxfreq].top();
        freq[maxfreq].pop();
        if(freq[maxfreq].empty()){
            freq.erase(maxfreq);
            maxfreq--;
        }
        m[f]--;
        if(m[f]==0){
            m.erase(f);
        }
        return f;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */