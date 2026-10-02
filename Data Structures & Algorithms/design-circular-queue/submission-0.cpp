class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next=NULL;
    }
};
class MyCircularQueue {
public:
    int size = 0;
    int maxsize;
    Node* head=NULL;
    MyCircularQueue(int k) {
        maxsize=k;
    }
    
    bool enQueue(int value) {
        if(head==NULL){
            Node* temp = new Node(value);
            head=temp;
            size=1;
        }else if(size==maxsize)
            return false;
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp= temp->next;
            }
            Node* node = new Node(value);
            temp->next = node;
            size++;
        }
        return true;
    }
    
    bool deQueue() {
        if(head==NULL){
            return false;
            size=0;
        }else{
            head = head->next;
            size--;
        }
        return true;
    }
    
    int Front() {
        if(head==NULL) return -1;
        return head->data;
    }
    
    int Rear() {
        if(head==NULL) return -1;
        Node* temp = head;
        while(temp->next){
            temp= temp->next;
        }
        return temp->data;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==maxsize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */