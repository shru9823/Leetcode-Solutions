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
    ListNode* oddEvenList(ListNode* head) {
        if(!head){return head;}
        ListNode* cur=head, *dummy1, *dummy2, *t1,*t2;
        dummy1 = new ListNode(0);dummy2 = new ListNode(0);
        t1=dummy1;
        t2=dummy2;
        bool odd=true;
        while(cur){
            if(odd){
                t1->next = cur;
                t1=t1->next;
                odd=false;}
            else{
                t2->next = cur;
                t2=t2->next;
                odd=true;}
            cout<<cur->val<<" "<<t1->val<<" "<<t2->val<<endl;
            cur = cur->next;
            
        }
        cout<<"hi"<<endl;
        t1->next = dummy2->next;
        if(t2){
        t2->next=NULL;}
        return (dummy1->next);
    }
};