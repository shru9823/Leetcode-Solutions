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
        ListNode* slow=head, *fast=head,*prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!prev){return;}
        prev = slow->next;
        slow->next = NULL;
        slow=prev;prev=NULL;
        while(slow){
            fast = slow->next;
            slow->next= prev;
            prev=slow;
            slow=fast;
        }
        slow=head;
        while(slow && prev){
            ListNode* temp = prev->next;
            prev->next = NULL;
            fast = slow->next;
            slow->next = prev;
            prev->next = fast;
            slow = fast;
            prev = temp;
        }
        return;
    }
};