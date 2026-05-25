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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* dummy = new ListNode(0,head);//saem as  the org LL 
        ListNode* op=dummy;
        while(curr!=NULL){
            if(curr->next!=NULL && curr->val==curr->next->val){//duplicate 
                while(curr->next!=NULL && curr->val==curr->next->val){
                    curr=curr->next;
                }
                op->next=curr->next;
            }
            else{//no duplicate 
                op=op->next;
            }
            //har case me curr aage badega hi
            curr=curr->next;
        }
        return dummy->next;
    }
};