/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> m;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        m[node]  = new Node(node->val,{});
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();q.pop();
            for(Node* nei:curr->neighbors)
            {
                if(m.find(nei)==m.end()){
                    m[nei] = new Node(nei->val,{}); 
                    q.push(nei);
                }
                m[curr]->neighbors.push_back(m[nei]);
            }
        }
        return m[node];
    }
};
