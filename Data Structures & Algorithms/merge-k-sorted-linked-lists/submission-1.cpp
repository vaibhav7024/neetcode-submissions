/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* merge(ListNode* h1,ListNode* h2){
        ListNode* temp = new ListNode(0);
        ListNode* dummy = temp;
        while(h1&&h2){
            if(h1->val<h2->val){
                temp->next = h1;
                h1 = h1->next;
            }else{
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }
        temp->next = h1?h1:h2;
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto l:lists){
            if(l!=NULL)
                pq.push({l->val,l});
        }
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();
            temp->next = a.second;
            temp = temp->next;
            if(a.second->next!=NULL)
                pq.push({a.second->next->val,a.second->next});
        }
        return res->next;
    }
};
