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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        int k = 1;
        while(k < n){
            for(int i=0;i+k<n;i=i+2*k){
                lists[i] = merge(lists[i], lists[i+k]);
            }
            k= 2*k;
        }
        return n>0?lists[0]:NULL;
    }
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* dummy = new ListNode();
        ListNode* cur=dummy;
        while(h1 && h2){
            if(h1->val <= h2->val){
                cur->next = h1;
                h1 = h1->next;
            }else{
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        if(h1){
            cur->next = h1;
        }
        else{
            cur->next = h2;
        }
        return dummy->next;
    }
};