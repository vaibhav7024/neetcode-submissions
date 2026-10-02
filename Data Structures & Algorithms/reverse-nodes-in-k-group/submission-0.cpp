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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count=0;
        while(temp && count<k){
            temp = temp->next;
            count++;
        }
        if(count<k) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        int counter=0;
        while(curr && counter<k){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            counter++;
        }
        if(curr!=NULL){
            ListNode* newhead = reverseKGroup(curr,k);
                head ->next = newhead;
        }
        return prev;
    }
};
