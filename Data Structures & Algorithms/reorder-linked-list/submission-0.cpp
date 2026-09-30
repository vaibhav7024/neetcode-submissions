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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        ListNode* prev=NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr =next;
        }
        slow->next= NULL;
        ListNode* temp = head->next;
        while(prev){
            head->next = prev;
            prev=prev->next;
            head=head->next;
            head->next = temp;
            temp = temp->next;
            head = head->next;
        }
    }
};
