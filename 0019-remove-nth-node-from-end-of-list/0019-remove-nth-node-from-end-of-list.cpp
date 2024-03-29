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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head;
        ListNode* dummy = new ListNode(0);
        ListNode* t = dummy;
        t->next=head;
        n--;
        while(n--){
            cur = cur->next;
        }
        while(cur->next){
            t = t->next; cur=cur->next;
        }
        t->next = t->next->next;
        return dummy->next;
    }
};