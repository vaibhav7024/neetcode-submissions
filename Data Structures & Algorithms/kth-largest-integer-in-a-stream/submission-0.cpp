class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> pq;
    int s ;
    KthLargest(int k, vector<int>& nums) {
        s=k;
        for(int num:nums){
            pq.push(num);
            while(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>s){
            pq.pop();
        }
        return pq.top();
    }
};
