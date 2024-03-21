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
    int pairSum(ListNode* head) {
        ListNode *fast=head, *slow=head, *prev=NULL;
        while(fast != NULL && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        ListNode *t=prev->next;
        prev->next = NULL;
        prev = t;
        while(t){
            ListNode* temp = t;
            t=t->next;
            temp->next = prev;
            prev = temp;
        }
        int ans=0;
        while(head){
            ans = max(ans, head->val + prev->val);
            head=head->next;prev=prev->next;
        }
        return ans;
    }
};